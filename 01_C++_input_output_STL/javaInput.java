public class Main {
  public static class main(String args[]){
    sc sc = new sc();
    String a = sc.readline();
  }
  static class sc {
  		private static BufferedReader br;
  		private static StringTokenizer st;

  		static void init() {
  			br = new BufferedReader(new InputStreamReader(System.in));
  			st = new StringTokenizer("");
  		}

  		static String readLine() {
  			try {
  				String input = br.readLine();

  				st = new StringTokenizer(input);

  				return input;
  			} catch (IOException e) {
  			}
  			return null;
  		}

  		static String readLineReplace() {
  			try {
  				return br.readLine().replaceAll("\\s+", "");
  			} catch (IOException e) {
  			}
  			return null;
  		}

  		static boolean hasNext() {
  			return st.hasMoreTokens();
  		}

  		static String next() {
  			while (!st.hasMoreTokens()) {
  				try {
  					st = new StringTokenizer(br.readLine());
  				} catch (IOException e) {
  				}
  			}
  			return st.nextToken();
  		}

  		static long nextLong() {
  			return Long.parseLong(next());
  		}

  		static int nextInt() {
  			return Integer.parseInt(next());
  		}

  		static double nextDouble() {
  			return Double.parseDouble(next());
  		}
  	}
}
