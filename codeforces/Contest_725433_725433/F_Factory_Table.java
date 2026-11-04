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
        int[] arr = new int[n];
        readArr(arr);
        int idx = 0;
        int max = 1;
        int curr = 1;
        int num_dec = 0;
        for(int i = 1; i < n; i++) {
            if (arr[i-1] < arr[i]) {
                curr++;
                if (curr >= max) {
                    max = curr;
                    idx = i-curr+1;
                }
            } else {
                num_dec++;
                curr = 1;
            }
        }
        if(num_dec >= 2) {
            out.println(max);
        } else if(num_dec == 1) {
            if(idx == 0) {
                int start = arr[idx + max]-1;
                out.println(arr[idx+max-1]/start);
            } else {
                int start = arr[idx]-1;
                out.println(arr[idx-1]/start);
            }
        } else {
            if (max == 1) {
                out.println(arr[0]);
            } else {
                int d = arr[idx+1]-arr[idx];
                out.println(Math.max(d, arr[idx+max-1]/d));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        // int t=1;
        while (t-->0) {
            solve();
        }
        out.close();
    }
};
