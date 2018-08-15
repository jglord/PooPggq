package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3.questao3;

import java.util.ArrayList;
import java.util.Scanner;

public class Principal {
	
	private ArrayList<Quadrilatero> quadrilateros = new ArrayList<Quadrilatero>();
	private ArrayList<Circulo> circulos = new ArrayList<Circulo>();
	private int quantCirculos;
	private int quantQuadrilateros;


	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Principal p = new Principal();
		
		System.out.println("Quantas formas você deseja criar?");
		int quantFormas = in.nextInt();
		
		for (int i = 0; i < quantFormas; i++) {
			mostrarOpcoes();
			System.out.print("Escolhe uma opção: ");
			int opcao = in.nextInt();
			
			p.instanciarObjeto(opcao);
			
		}
		
		// Exibindo quadrilateros
		for (int i = 0; i < p.getQuantQuadrilateros(); i++) {
			p.getQuadrilateros().get(i).calcularArea();
			p.getQuadrilateros().get(i).calcularPerimetro();
			
			System.out.println("\n" + (i+1) + "°" + " quadrilatero...");
			System.out.println("AREA: " + p.getQuadrilateros().get(i).getArea());
			System.out.println("PERIMETRO: " + p.getQuadrilateros().get(i).getPerimetro());
		}
		
		// Exibindo circulos
		for (int i = 0; i < p.getQuantCirculos(); i++) {
			p.getCirculos().get(i).calcularArea();
			p.getCirculos().get(i).calcularPerimetro();
			
			System.out.println("\n" + (i+1) + "°" + " circulo...");
			System.out.println("AREA: " + p.getCirculos().get(i).getArea());
			System.out.println("PERIMETRO: " + p.getCirculos().get(i).getPerimetro());
		}
		
		
		in.close();
	}
	
	
	public static void mostrarOpcoes() {
		System.out.println("1 - Quadrado");
		System.out.println("2- Retangulo");
		System.out.println("3 - Circulo");
	}
	
	public void instanciarObjeto(int opcao) {
		Scanner inn = new Scanner(System.in);
		
		switch (opcao) {
		case 1:
			System.out.print("Informe o lado do quadrado: ");
			double lado = inn.nextDouble();			
			
			Quadrado quadrado = new Quadrado(lado);	
			this.getQuadrilateros().add(quadrado);
			this.setQuantQuadrilateros();
			
			break;
		case 2:
			System.out.print("Informe a base do retangulo: ");
			double base = inn.nextDouble();
			
			System.out.println("Informe a altura do retangulo: ");
			double altura = inn.nextDouble();
			
			Retangulo retangulo = new Retangulo(base, altura);
			this.getQuadrilateros().add(retangulo);			
			this.setQuantQuadrilateros();
			
			break;
		case 3:
			System.out.println("Informe o raio do circulo");
			double raio = inn.nextDouble();
			
			Circulo circulo = new Circulo(raio);
			
			this.getCirculos().add(circulo);
			
			this.setQuantCirculos();
			break;
		default:
			break;
		}
	}

	public ArrayList<Quadrilatero> getQuadrilateros() {
		return quadrilateros;
	}
	
	
	public void setQuadrilateros(ArrayList<Quadrilatero> quadrilateros) {
		this.quadrilateros = quadrilateros;
	}
	
	
	public ArrayList<Circulo> getCirculos() {
		return circulos;
	}
	
	
	public void setCirculos(ArrayList<Circulo> circulos) {
		this.circulos = circulos;
	}
	
	
	public int getQuantCirculos() {
		return quantCirculos;
	}
	
	
	public void setQuantCirculos() {
		this.quantCirculos++;
	}
	
	
	public int getQuantQuadrilateros() {
		return quantQuadrilateros;
	}
	
	
	public void setQuantQuadrilateros() {
		this.quantQuadrilateros++;
	}
}


















