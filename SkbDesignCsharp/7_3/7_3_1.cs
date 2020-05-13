using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegates.Reports
{
	public abstract class ReportMaker
	{
		protected readonly IReportData _reportData;

		public ReportMaker(IReportData reportData)
		{
			_reportData = reportData;
		}

		protected abstract string MakeCaption(string caption);
		protected abstract string BeginList();
		protected abstract string MakeItem(string valueType, string entry);
		protected abstract string EndList();

		protected virtual object MakeStatistics(IEnumerable<double> data)
		{
			return _reportData.GetData(data);
		}

		protected virtual string Caption
		{
			get
			{
				return _reportData.Caption;
			}
		}
		
		public string MakeReport(IEnumerable<Measurement> measurements)
		{
			var data = measurements.ToList();
			var result = new StringBuilder();
			result.Append(MakeCaption(Caption));
			result.Append(BeginList());
			result.Append(MakeItem("Temperature", MakeStatistics(data.Select(z => z.Temperature)).ToString()));
			result.Append(MakeItem("Humidity", MakeStatistics(data.Select(z => z.Humidity)).ToString()));
			result.Append(EndList());
			return result.ToString();
		}
	}
	
	public interface IReportData
	{
		string Caption { get; }

		object GetData(IEnumerable<double> data);
	}

	public class MeanAndStdReportData : IReportData
	{
		public string Caption
		{
			get { return "Mean and Std"; }
		}
		
		public object GetData(IEnumerable<double> _data)
		{
			var data = _data.ToList();
			var mean = data.Average();
			var std = Math.Sqrt(data.Select(z => Math.Pow(z - mean, 2)).Sum() / (data.Count - 1));

			return new MeanAndStd
			{
				Mean = mean,
				Std = std
			};
		}
	}

	public class MedianReportData : IReportData
	{
		public string Caption
		{
			get { return "Median"; }
		}
		
		public object GetData(IEnumerable<double> data)
		{
			var list = data.OrderBy(z => z).ToList();
			if (list.Count % 2 == 0)
				return (list[list.Count / 2] + list[list.Count / 2 - 1]) / 2;
			
			return list[list.Count / 2];
		}
	}
	
	public class HtmlReportMaker<T> : ReportMaker where T : IReportData, new()
	{
		public HtmlReportMaker(T data) : base(data)
		{
		}
		
		protected override string MakeCaption(string caption)
		{
			return $"<h1>{caption}</h1>";
		}

		protected override string BeginList()
		{
			return "<ul>";
		}

		protected override string EndList()
		{
			return "</ul>";
		}

		protected override string MakeItem(string valueType, string entry)
		{
			return $"<li><b>{valueType}</b>: {entry}";
		}
	}

	public class MarkdownReportMaker<T> : ReportMaker where T : IReportData, new()
	{
		public MarkdownReportMaker(T data) : base (data)
		{
		}
		protected override string BeginList()
		{
			return "";
		}

		protected override string EndList()
		{
			return "";
		}

		protected override string MakeCaption(string caption)
		{
			return $"## {caption}\n\n";
		}

		protected override string MakeItem(string valueType, string entry)
		{
			return $" * **{valueType}**: {entry}\n\n";
		}
	}

	public static class ReportMakerHelper
	{
		public static string MeanAndStdHtmlReport(IEnumerable<Measurement> data)
		{
			return new HtmlReportMaker<MeanAndStdReportData>(new MeanAndStdReportData()).MakeReport(data);
		}

		public static string MedianMarkdownReport(IEnumerable<Measurement> data)
		{
			return new MarkdownReportMaker<MedianReportData>(new MedianReportData()).MakeReport(data);
		}

		public static string MeanAndStdMarkdownReport(IEnumerable<Measurement> measurements)
		{
			return new MarkdownReportMaker<MeanAndStdReportData>(new MeanAndStdReportData()).MakeReport(measurements);
		}

		public static string MedianHtmlReport(IEnumerable<Measurement> measurements)
		{
			return new HtmlReportMaker<MedianReportData>(new MedianReportData()).MakeReport(measurements);
		}
	}
}