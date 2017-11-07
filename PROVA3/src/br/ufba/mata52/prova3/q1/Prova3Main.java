package br.ufba.mata52.prova3.q1;

public class Prova3Main {
	private final int V = 0, W = 1;
//	private final int B = 10;
//	private int[][] input = new int[][]{
//			{30,6}, {14,3}, {16,4}, {9,2}, {11,1}, {15,5}
//	};
	
	private final int B = 50;
	private int[][] input = new int[][]{
			{60,10}, {100,20}, {120,30}
	};

	private int[][] output = new int[input.length + 1][B + 1];

	public Prova3Main() {
//		F();
		System.out.println(M(input.length, B));
	}

//	public void F() {
//		for(int i = 1; i < output.length; i++) {
//			for(int j = 1; j < output[i].length; j++) {
//				output[i][j] = Math.max(output[i - 1][j], j/input[i - 1][W] * input[i - 1][V]);
//			}
//		}
//
//		for(int i = 0; i < output.length; i++) {
//			for(int j = 0; j < output[i].length; j++) {
//				if(j == 0)
//					System.out.print(String.format("%02d", output[i][j]));
//				else 
//					System.out.print(String.format(", %02d", output[i][j]));
//			}
//			System.out.println("");
//		}
//	}

	public int M(int i, int b) {
		if(i == 0 || b == 0)
			return 0;
		if(input[i - 1][W] > b) {
			return M(i - 1, b);
		} else {
			return Math.max(
					input[i - 2][V] + M(i - 1,b - input[i - 1][W]), 
					M(i - 1, b)
				);
		}
	}

	public static void main(String[] args) {
		new Prova3Main();
	}

}
