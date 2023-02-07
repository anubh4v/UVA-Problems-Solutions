import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class foo {

	final static private PrintWriter out = new PrintWriter(System.out);
	static FastReader sc = new FastReader();
	// static Scanner sc = new Scanner(System.in);
	public static int M = 1000000007;
	static int[] dx = {0, 0, -1}, dy = {-1, 1, 0};
	static char[] ch = {'I', 'E', 'H', 'O', 'V', 'A', '#'};

	public static void solve() {
		int n = sc.nextInt(), m = sc.nextInt();

		char[][] a = new char[n][m];

		for(int i=0; i<n; ++i) a[i] = sc.next().toCharArray();
		for(int j=0; j<m; ++j) {
			if(a[n-1][j] == '@') {
				dfs(n-1, j, 0, a);
			}
		}
	}

	public static void dfs(int i, int j, int l, char[][] a) {
		if(l == 7) {
			out.println();
			return;
		}
		for(int f=0; f<dx.length; ++f) {
			if(check(i+dx[f], j+dy[f],a.length, a[0].length) && a[i+dx[f]][j+dy[f]]==ch[l]) {
				if(f==0) {
					out.print("left");
				}
				else if(f==1) {
					out.print("right");
				}
				else out.print("forth");
				if(l!=6)out.print(" ");
				dfs(i+dx[f], j+dy[f], l+1, a);
			}
		}
	}

	public static boolean check(int i, int j, int n, int m) {
		if(i<0 || i>=n || j<0 || j>=m) return false;
		else return true;
	}

	public static void main(String args[]) {
		int t = 1;
		t = sc.nextInt();
		//sc.nextLine();
		while(t-->0) {
			// System.out.println("--------------");
			solve();
		}
		out.close();
		return;
	}
	
	// static class Pair implements Comparable<Pair>{
	// 	int f;
	// 	int s;

	// 	Pair (int a, int b) {
	// 		f = a; 
	// 		s = b;
	// 	}

	// 	@Override
	// 	int compareTo(Pair a) {
	// 		if(a.s > this.s) return 1;
	// 		else return -1;
	// 	}
	// }


	public static long intSqrt(long a) {
		long x = (long)Math.sqrt(a)+2;
		while(x*x>a) x--;
		return x;
	}

	public static int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

	public static long fact(int i) {
		if(i==0) return 1;
		long ans = i;
		while(--i>0) {
			ans = (ans*i)%M;
		}
		return ans;
	}

	public static int x;
	public static int y;

	static int gcdExtended(int a, int b) {
		if(a==0) {
			x = 0;
			y = 1;
			return b;
		}

		int gcd = gcdExtended(b%a, a);
		int x1 = x;
		int y1 = y;

		int tmp = b/a;
		x = y1 - tmp * x1;
		y = x1;

		return gcd;
	}

	static long  modInverse(int A, int M) {
		int g = gcdExtended(A, M);
		long res = 0;
		if(g != 1) {
			throw new ArithmeticException("Inverse doesn't exist");
		}
		else {
			res = (x%M + M) % M;
		}
		return res;
	}

	static final Random random = new Random();

	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
 
		public FastReader()
		{
			br = new BufferedReader(
				new InputStreamReader(System.in));
		}
 
		String next()
		{
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				}
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() { return Integer.parseInt(next()); }
 
		long nextLong() { return Long.parseLong(next()); }
 
		double nextDouble()
		{
			return Double.parseDouble(next());
		}
 
		String nextLine()
		{
			String str = "";
			try {
				str = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}
