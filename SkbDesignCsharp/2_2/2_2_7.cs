class MyFile
{
    public static string ReadAll(string filename, Encoding enc = null)
    {
        if (enc == null)
        {
          enc = Encoding.UTF8;
        }
        Console.WriteLine("Use encoding " + enc);
        return null;
    }  
}