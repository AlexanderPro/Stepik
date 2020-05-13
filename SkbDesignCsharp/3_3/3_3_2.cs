using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Incapsulation.EnterpriseTask
{
    public class Enterprise
    {
        string inn;

        public Guid Guid { get; }

        public string Name { get; set; }

        public DateTime EstablishDate { get; set; }

        public string Inn
        {
            get
            {
                return inn;
            }

            set
            {
                if (value.Length != 10 || !value.All(z => char.IsDigit(z)))
                    throw new ArgumentException();
                inn = value;
            }
        }

        public TimeSpan ActiveTimeSpan
        {
            get
            {
                return DateTime.Now - EstablishDate;
            }
        }

        public double GetTotalTransactionsAmount()
        {
            DataBase.OpenConnection();
            var amount = 0.0;
            foreach (Transaction t in DataBase.Transactions().Where(z => z.EnterpriseGuid == Guid))
                amount += t.Amount;
            return amount;
        }

        public Enterprise(Guid guid)
        {
            Guid = guid;
        }
    }
}