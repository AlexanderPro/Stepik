using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance.Geometry
{
	public abstract class Body
	{
		public abstract double GetVolume();
	}

	public class Ball : Body
	{
		public double Radius { get; set; }
		
		public override double GetVolume()
		{
			return 4.0 * Math.PI * Math.Pow(Radius, 3) / 3;
		}
	}

	public class Cube : Body
	{
		public double Size { get; set; }
		
		public override double GetVolume()
		{
			return Math.Pow(Size, 3);
		}
	}

	public class Cylinder : Body
	{
		public double Height { get; set; }
		public double Radius { get; set; }
		
		public override double GetVolume()
		{
			return Math.PI * Math.Pow(Radius, 2) * Height;
		}
	}

	// Заготовка класса для задачи на Visitor
	public class SurfaceAreaVisitor
	{
		public double SurfaceArea { get; private set; }
	}
	public class DimensionsVisitor
	{
		public Dimensions Dimensions { get; private set; }
	}
}