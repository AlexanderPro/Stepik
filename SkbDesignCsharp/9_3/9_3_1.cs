using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Memory.API
{
    public class APIObject : IDisposable
    {
        private readonly int _id;
        private bool _isDisposed;
        
        public APIObject(int id)
        {
            _id = id;
            MagicAPI.Allocate(id);
        }
        
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        
        protected virtual void Dispose(bool disposing)
        {
            if (!_isDisposed)
            {
                if (disposing)
                {
                }

                MagicAPI.Free(_id);
                _isDisposed = true;
            }
        }
        
        ~APIObject()
        {
            Dispose(false);
        }
    }
}