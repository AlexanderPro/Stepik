using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Incapsulation.Failures
{
    public class Common
    {
        public static bool Earlier(DateTime deviceDate, DateTime givenDate)
        {
            return deviceDate < givenDate;
        }
    }

    public enum FailureType
    {
        UnexpectedShutdown,
        NonResponding,
        HardwareFailures,
        ConnectionProblems
    }

    public class Failure
    {
        public FailureType FailureType { get; set; }

        public bool IsFailureSerious()
        {
            return (int)FailureType % 2 == 0;
        }
    }

    public class Device
    {
        public int Id { get; set; }

        public string Name { get; set; }

        public DateTime Date { get; set; }

        public Failure Failure { get; set; }
    }

    public class ReportMaker
    {
        /// <summary>
        /// </summary>
        /// <param name="day"></param>
        /// <param name="failureTypes">
        /// 0 for unexpected shutdown, 
        /// 1 for short non-responding, 
        /// 2 for hardware failures, 
        /// 3 for connection problems
        /// </param>
        /// <param name="deviceId"></param>
        /// <param name="times"></param>
        /// <param name="devices"></param>
        /// <returns></returns>
        public static List<string> FindDevicesFailedBeforeDateObsolete(
            int day,
            int month,
            int year,
            int[] failureTypes,
            int[] deviceId,
            object[][] times,
            List<Dictionary<string, object>> devices)
        {
            var data = new List<Device>();
            for (int i = 0; i < devices.Count; i++)
            {
                data.Add(new Device
                {
                    Id = (int)devices[i]["DeviceId"],
                    Name = (string)devices[i]["Name"],
                    Failure = new Failure { FailureType = (FailureType)failureTypes[i] },
                    Date = new DateTime((int)times[i][2], (int)times[i][1], (int)times[i][0]),
                });
            }

            data = FindDevicesFailedBeforeDate(new DateTime(year, month, day), data);
            return data.Select(x => x.Name).ToList();
        }

        public static List<Device> FindDevicesFailedBeforeDate(DateTime givenDate, List<Device> devices)
        {
            return devices
                .Where(x => x.Failure.IsFailureSerious() && Common.Earlier(x.Date, givenDate))
                .ToList();
        }
    }
}