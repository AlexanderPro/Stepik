using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Streams.Resources
{
    public class ResourceReaderStream : Stream
    {
        private readonly Stream _baseStream;
        private readonly string _key;
        private byte[] _data;
        private int _position;
        private int _positionEnd;
        private bool _keyFound;
        private bool _readNextData;
        
        public ResourceReaderStream(Stream stream, string key)
        {
            _baseStream = stream;
            _key = key;
            _keyFound = false;
            _data = new byte[0];
            _position = 0;
            _positionEnd = 0;
            _readNextData = false;
        }

        public override int Read(byte[] buffer, int offset, int count)
        {
            var length = 0;
            var temp = new byte[0];

            if (_keyFound)
            {
                if (_position == _positionEnd && _readNextData)
                {
                    _data = new byte[Constants.BufferSize];
                    _position = 0;
                    _positionEnd = 0;
                    _readNextData = false;

                    var cnt = _baseStream.Read(_data, 0, Constants.BufferSize);
                    if (cnt == 0)
                    {
                        return cnt;
                    }
                }
                else
                {
                    length = _positionEnd - _position; 
                    length = length < count ? length : count;
                    Array.Copy(_data, _position, buffer, offset, length);
                    _position += length;
                    temp = ReplaceBytes(SubArray(buffer, 0, length), new byte[] {0, 0}, new byte[] {0});
                    if (temp != null)
                    {
                        Array.Copy(temp, 0, buffer, 0, temp.Length);
                        length = temp.Length;
                    }
                    return length;
                }
            }
            else
            {
                _data = new byte[Constants.BufferSize];
                _baseStream.Read(_data, 0, Constants.BufferSize);
                _position = 0;
                _positionEnd = 0;
                _readNextData = false;
            }

            foreach (var index in StartingIndex(_data, new byte[] {0, 1}))
            {
                if (!_keyFound)
                {
                    var subarray = SubArray(_data, _position, index - _position);
                    var str = Encoding.ASCII.GetString(subarray);
                    if (_key == str)
                    {
                        _keyFound = true;
                    }
                    _position += (index - _position) + 2;
                }
                else
                {
                    length = index - _position; 
                    length = length < count ? length : count;
                    Array.Copy(_data, _position, buffer, offset, length);
                    _position += length;
                    _positionEnd = index;
                    temp = ReplaceBytes(SubArray(buffer, 0, length), new byte[] {0, 0}, new byte[] {0});
                    if (temp != null)
                    {
                        Array.Copy(temp, 0, buffer, 0, temp.Length);
                        length = temp.Length;
                    }
                    return length;
                }
            }

            if (!_keyFound)
            {
                return 0;
            }
            
            length = _data.Length - _position; 
            length = length < count ? length : count;
            Array.Copy(_data, _position, buffer, offset, length);
            _position += length;
            _positionEnd = _data.Length;
            _readNextData = true;
            temp = ReplaceBytes(SubArray(buffer,0, length), new byte[] {0, 0}, new byte[] {0});
            if (temp != null)
            {
                Array.Copy(temp, 0, buffer, 0, temp.Length);
                length = temp.Length;
            }
            return length;
        }
        
        public IEnumerable<int> StartingIndex(byte[] x, byte[] y) {
            IEnumerable<int> index = Enumerable.Range(0, x.Length - y.Length + 1);
            for (int i = 0; i < y.Length; i++) {
                index = index.Where(n => x[n + i] == y[i]).ToArray();
            }
            return index;
        }
        
        public T[] SubArray<T>(T[] data, int index, int length)
        {
            T[] result = new T[length];
            Array.Copy(data, index, result, 0, length);
            return result;
        }
        
        public int FindBytes(byte[] src, byte[] find)
        {
            int index = -1;
            int matchIndex = 0;
            // handle the complete source array
            for(int i=0; i<src.Length; i++)
            {
                if(src[i] == find[matchIndex])
                {
                    if (matchIndex==(find.Length-1))
                    {
                        index = i - matchIndex;
                        break;
                    }
                    matchIndex++;
                }
                else if (src[i] == find[0])
                {
                    matchIndex = 1;
                }
                else
                {
                    matchIndex = 0;
                }
            }
            return index;
        }

        public byte[] ReplaceBytes(byte[] src, byte[] search, byte[] repl)
        {
            byte[] dst = null;
            int index = FindBytes(src, search);
            if (index>=0)
            {
                dst = new byte[src.Length - search.Length + repl.Length];
                // before found array
                Buffer.BlockCopy(src,0,dst,0, index);
                // repl copy
                Buffer.BlockCopy(repl,0,dst,index,repl.Length);
                // rest of src array
                Buffer.BlockCopy(
                    src, 
                    index+search.Length , 
                    dst, 
                    index+repl.Length, 
                    src.Length-(index+search.Length));
            }
            return dst;
        }

        private void SeekValue()
        {
        }

        public override void Flush()
        {
        }
        
        public override bool CanRead
        {
            get
            {
                throw new NotImplementedException();
            }
        }

        public override bool CanSeek
        {
            get
            {
                throw new NotImplementedException();
            }
        }

        public override bool CanWrite
        {
            get
            {
                throw new NotImplementedException();
            }
        }

        public override long Length
        {
            get
            {
                throw new NotImplementedException();
            }
        }

        public override long Position
        {
            get
            {
                throw new NotImplementedException();
            }

            set
            {
                throw new NotImplementedException();
            }
        }

        public override long Seek(long offset, SeekOrigin origin)
        {
            throw new NotImplementedException();
        }

        public override void SetLength(long value)
        {
            throw new NotImplementedException();
        }

        public override void Write(byte[] buffer, int offset, int count)
        {
            throw new NotImplementedException();
        }
    }
}