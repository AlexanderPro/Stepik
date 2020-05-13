using System.Collections.Generic;
using System.Linq;

namespace Delegates.TreeTraversal
{
   public static class Traversal
   {
      public static IEnumerable<Job> GetEndJobs(this Job job)
      {
         var storedJobs = new List<Job>();
         
         foreach (var subjob in job.Subjobs)
         {
            if (subjob.Subjobs.Any())
            {
               foreach (var sjob in subjob.GetEndJobs())
               {
                  yield return sjob;
               }
            }
            else
            {
               storedJobs.Add(subjob);
            }
         }

         foreach (var storedJob in storedJobs)
         {
            yield return storedJob;
         }
         
         if (!job.Subjobs.Any())
         {
            yield return job;
         }
      }
      
      public static IEnumerable<Product> GetProducts(this ProductCategory data)
      {
         foreach (var category in data.Categories)
         {
            foreach (var product in category.GetProducts())
            {
               yield return product;
            }
         }
         
         foreach (var product in data.Products)
         {
            yield return product;
         }
      }

      public static IEnumerable<T> GetBinaryTreeValues<T>(this BinaryTree<T> data)
      {
         yield return data.Value;
         
         if (data.Left != null)
         {
            foreach (T item in data.Left.GetBinaryTreeValues())
            {
               yield return item;
            }
         }

         if (data.Right != null)
         {
            foreach (T item in data.Right.GetBinaryTreeValues())
            {
               yield return item;
            }
         }
      }
   }
}