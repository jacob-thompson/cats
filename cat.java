import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class cat
{
    public static void main(String args[])
    {
        try
        {
            File catFile = new File("art.txt");
            Scanner catReader = new Scanner(catFile);
            while (catReader.hasNextLine())
            {
                String data = catReader.nextLine();
                System.out.println(data);
            }
        }
        catch (FileNotFoundException err)
        {
            System.out.println("ERROR: File not found.\n");
            err.printStackTrace();
        }
    }
}
