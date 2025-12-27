using System;
using System.IO;
using System.Xml.Linq;
using System.Xml.Xsl;

class Program
{
    static void Main()
    {
        // Load XSLT
        var xslt = new XslCompiledTransform();
        xslt.Load("transform.xslt");

        // Transform and overwrite original file
        xslt.Transform("input.xml", "input.xml");

        // Verify output (now modified in-place)
        Console.WriteLine(File.ReadAllText("input.xml"));
    }
}
