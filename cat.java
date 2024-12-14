import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class cat
{
    static int getMessageCount() throws FileNotFoundException, IOException
    {
        BufferedReader reader = new BufferedReader(new FileReader("support.txt"));
        int count = 0;
        while (reader.readLine() != null)
            count++;

        reader.close();
        return count;
    }
    static String getMessage(int messageCount) throws FileNotFoundException
    {
        Random rand = new Random();
        int messageIndex = rand.nextInt(messageCount);

        String message = "";
        Scanner sc = new Scanner(new File("support.txt"));
        int count = 0;
        while (sc.hasNextLine())
        {
            message = sc.nextLine();
            if (messageIndex == count)
                break;
            count++;
        }

        sc.close();
        return message;
    }

    static void printBubble(String message)
    {
        int length = message.length(); 
        int bubbleWidth = length + 4;

        // top of bubble
        System.out.print("  ");
        for (int i = 0; i < bubbleWidth; i++)
            System.out.print("_");
        System.out.println();

        // middle of bubble
        System.out.print(" / ");
        for (int i = 0; i < bubbleWidth - 2; i++)
            System.out.print(" ");
        System.out.println(" \\");

        // message
        System.out.println(" |  " + message + "  |");

        // bottom of bubble
        System.out.print(" \\ ");
        for (int i = 0; i < bubbleWidth - 2; i++)
            System.out.print("_");
        System.out.println(" /");

    }

    static void printCat() throws FileNotFoundException
    {
        Scanner sc = new Scanner(new File("cat.txt"));
        while (sc.hasNextLine())
        {
            System.out.println(sc.nextLine());
        }
        sc.close();
    }

    public static void main(String args[])
    {
        try
        {
            int messageCount = getMessageCount();
            String message = getMessage(messageCount);
            printBubble(message);
            printCat();
        }
        catch (FileNotFoundException err)
        {
            System.out.println("ERROR: File not found.\n");
            err.printStackTrace();
        }
        catch (IOException err)
        {
            System.out.println("ERROR: IO Exception.\n");
            err.printStackTrace();
        }
    }
}
