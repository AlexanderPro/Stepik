using System;
using System.Collections.Generic;
using System.Text;

namespace Delegates.Observers
{
	public class StackOperationsLogger
	{
		private StringBuilder Log = new StringBuilder();

		public void SubscribeOn<T>(ObservableStack<T> stack)
		{
			stack.StackEvent += (sender, data) =>
			{
				Log.Append(data);
			};
		}

		public string GetLog()
		{
			return Log.ToString();
		}
	}

	public class ObservableStack<T>
	{
		public event EventHandler<StackEventData<T>> StackEvent; 

		private List<T> data = new List<T>();

		public void Push(T obj)
		{
			data.Add(obj);
			if (StackEvent != null)
			{
				StackEvent.Invoke(this, new StackEventData<T> {IsPushed = true, Value = obj});
			}
		}

		public T Pop()
		{
			if (data.Count == 0)
				throw new InvalidOperationException();
			var result = data[data.Count - 1];
			if (StackEvent != null)
			{
				StackEvent.Invoke(this, new StackEventData<T> {IsPushed = false, Value = result});
			}
			return result;
		}
	}
}