import java.util.*;
import java.lang.*;
import java.io.*;
 
public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter out = new PrintWriter(System.out);
 
    public static void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            out.print(arr[i] + " ");
        }
        out.println();
    } // change array type as needed

    public static void printArr(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            out.print(arr[i] + " ");
        }
        out.println();
    } // change array type as needed
 
    public static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
 
    public static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }
 
    public static void readArr(int[] arr) throws IOException {
        int n = arr.length;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }
 
    public static void readArr(long[] arr) throws IOException {
        int n = arr.length;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
    }
 
    public static boolean isPrime(int n) {
        if (n == 1)
            return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    public static void sort(long[] arr) {
        int n = arr.length;
        Random rnd = new Random();
        for (int i = 0; i < n; i++) {
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n - i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
        Arrays.sort(arr);
    }
 
    public static void sort(int[] arr) {
        int n = arr.length;
        Random rnd = new Random();
        for (int i = 0; i < n; i++) {
            int tmp = arr[i];
            int randomPos = i + rnd.nextInt(n - i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
        Arrays.sort(arr);
    }

    public static void solve() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        char[] arr = br.readLine().toCharArray();
        int[] pref = new int[n+1];
        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + (arr[i] == '4' ? 1 : 0);
        }
        while(q-->0) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken())-1;
            int r = Integer.parseInt(st.nextToken())-1;
            int x = Math.abs(Integer.parseInt(st.nextToken()));
            int y = Math.abs(Integer.parseInt(st.nextToken()));
            int cnt4 = pref[r+1] - pref[l];
            int cnt8 = r-l+1 - cnt4;
            if(Math.max(0, x-cnt8) + Math.max(0, y-cnt8) <= cnt4) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }
    }

    public static void main(String[] args) throws IOException {
        // int t = Integer.parseInt(br.readLine());
        int t=1;
        while (t-->0) {
            solve();
        }
        out.close();
    }
};
