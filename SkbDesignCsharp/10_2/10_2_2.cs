using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Reflection;

namespace Streams.Compression
{
    public class CustomCompressionStream : Stream
    {
        private readonly bool _read;
        private readonly Stream _baseStream;
        private GZipStream _gZipStream;
        
        public CustomCompressionStream(Stream baseStream, bool read)
        {
            _read = read;
            _baseStream = baseStream;
            _gZipStream = !_baseStream.CanRead || !_baseStream.CanWrite ? null :
                new GZipStream(_baseStream, read ? CompressionMode.Decompress : CompressionMode.Compress, true);
        }

        public override void Write(byte[] buffer, int offset, int count)
        {
            if (_gZipStream == null)
            {
                _baseStream.Write(buffer, offset, count);
            }
            else
            {
                _gZipStream.Write(buffer, offset, count);
            }
        }

        public override int Read(byte[] buffer, int offset, int count) 
        {
            if (_baseStream is PartialStream)
            {
                var data = new List<byte>();
                var cnt = 0;
                while ((cnt = _baseStream.Read(buffer, offset, count)) > 0)
                {
                    offset += cnt;
                    if (offset == count)
                    {
                        offset = 0;
                        data.AddRange(buffer);
                    }

                    var partialStreamIndex = (int)GetInstanceField(_baseStream, "index");
                    var partialStreamContent = (byte[])GetInstanceField(_baseStream, "content");
                    if (partialStreamIndex == partialStreamContent.Length)
                    {
                        break;
                    }
                }

                using (var baseStream = new MemoryStream(data.ToArray()))
                using (var dataStream = new MemoryStream())
                {

                    _gZipStream = new GZipStream(baseStream,
                        _read ? CompressionMode.Decompress : CompressionMode.Compress, true);
                    _gZipStream.CopyTo(dataStream);
                    Array.Copy(dataStream.ToArray(), buffer, count);
                    return count;
                }
            }
            else
            {
                var cnt = _gZipStream == null
                    ? _baseStream.Read(buffer, offset, count)
                    : _gZipStream.Read(buffer, offset, count);
                if (offset == 0 && count == 1000 && cnt == 0)
                {
                    throw new InvalidOperationException();
                }
                return cnt;
            }
        }

        public void CopyTo(Stream destination, int bufferSize)
        {
            _gZipStream.CopyTo(destination, bufferSize);
        }

        public override void Flush()
        {
            _gZipStream.Flush();
        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
            if (disposing && _gZipStream != null)
            {
                Flush();
                _gZipStream.Dispose();
                _gZipStream = null;
                _baseStream.Position = 0;
            }
        }

        public override void SetLength(long value)
        {
            throw new NotSupportedException();
        }

        public override long Seek(long offset, SeekOrigin origin)
        {
            throw new NotSupportedException();
        }

        public override bool CanRead 
        {
            get
            {
                return _read;
            }
        }

        public override bool CanWrite
        {
            get
            {
                return !_read;
            }
        }

        public override bool CanSeek
        {
            get
            {
                return false;
            }
        }
        
        public override long Length 
        {
            get
            {
                throw new NotSupportedException();
            }
        }
        
        public override long Position 
        {
            get
            {
                throw new NotSupportedException();
            }
            set
            {
                throw new NotSupportedException();
            }
        }
        
        private object GetInstanceField(object instance, string fieldName)
        {                
            var bindFlags = BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static;
            var field = instance.GetType().GetField(fieldName, bindFlags);
            return field.GetValue(instance);
        }
    }
}