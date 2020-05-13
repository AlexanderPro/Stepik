using System;
using System.Linq.Expressions;

namespace Reflection.Differentiation
{
   public static class Algebra
   {
      public static Expression<Func<double, double>> Differentiate(Expression<Func<double, double>> expression)
      {
         const double eps = 1e-7;
         var constEps = Expression.Constant(eps);
         var parameter = expression.Parameters[0];
         var add = Expression.Add(parameter, constEps);
         var addInvoke = Expression.Invoke(expression, add);
         var invoke = Expression.Invoke(expression, parameter);
         var subtract = Expression.Subtract(addInvoke, invoke);
         var divide = Expression.Divide(subtract, constEps);
         var result = Expression.Lambda<Func<double, double>>(divide, parameter);
         return result;
      }
   }
}