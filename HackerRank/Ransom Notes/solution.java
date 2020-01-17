import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the checkMagazine function below.
    static void checkMagazine(String[] magazine, String[] note) 
    {
        Map<String,Integer> mp=new HashMap<>();
        for(int i=0;i<magazine.length;i++)
        {
            if(mp.get(magazine[i])==null)
                mp.put(magazine[i],1);
            else
            {
                int k=mp.get(magazine[i]);
                k++;
                mp.put(magazine[i],k);
            }
        }
        int cnt=0;
        for(int i=0;i<note.length;i++)
        {
            if(mp.get(note[i])==null||mp.get(note[i])<=0)
            {
                cnt++;
                break;
            }
            else
            {
                int k=mp.get(note[i]);
                k--;
                mp.put(note[i],k);
            }
        }
        if(cnt>0)
            System.out.println("No");
        else
            System.out.println("Yes");
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] mn = scanner.nextLine().split(" ");

        int m = Integer.parseInt(mn[0]);

        int n = Integer.parseInt(mn[1]);

        String[] magazine = new String[m];

        String[] magazineItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            String magazineItem = magazineItems[i];
            magazine[i] = magazineItem;
        }

        String[] note = new String[n];

        String[] noteItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            String noteItem = noteItems[i];
            note[i] = noteItem;
        }

        checkMagazine(magazine, note);

        scanner.close();
    }
}
s