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
        long l = Long.parseLong(st.nextToken());
        long r = Long.parseLong(st.nextToken());
        long[] arr = new long[n];
        readArr(arr);
        sort(arr);
        long cnt_l = 0;
        long sum_l = 0;
        long cnt_r = 0;
        long sum_r = 0;
        Deque<Long> a = new LinkedList<>();
        for(long x : arr) {
            if(x <= l) {
                cnt_l++;
                sum_l += x;
            } else if(r <= x) {
                cnt_r++;
                sum_r += x;
            } else {
                a.addLast(x);
            }
        }
        long ans = 0;
        while(cnt_l < cnt_r && !a.isEmpty()) {
            cnt_l++;
            sum_l += a.removeFirst();
        }
        while(cnt_l > cnt_r && !a.isEmpty()) {
            cnt_r++;
            sum_r += a.removeLast();
        }
        if(cnt_l != cnt_r) {
            if (cnt_l < cnt_r) {
                ans = sum_r - cnt_r*r + cnt_l*r - sum_l;
            }
            else {
                ans = sum_r - cnt_r*l + cnt_l*l - sum_l;
            }
        } else {
            ans = sum_r - sum_l;
            while(a.size() > 1) {
                ans += a.removeLast() - a.removeFirst();
            }
        }
        out.println(ans);
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
