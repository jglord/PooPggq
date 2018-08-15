package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3.questao3;

public abstract class Quadrilatero implements FormaGeometrica{
	private double lado1, lado2, lado3, lado4;
	private double perimetro, area;
	
	public Quadrilatero(){}

	public Quadrilatero(double lado1, double lado2, double lado3, double lado4) {
		this.setLado1(lado1);
		this.setLado2(lado2);
		this.setLado3(lado3);
		this.setLado4(lado4);
	}
	
	@Override
	public void calcularPerimetro() {
		double peri = getLado1() + getLado2() + getLado3() + getLado4();
		setPerimetro(peri);
	}
	
	public double getLado1() {
		return lado1;
	}

	public void setLado1(double lado1) {
		this.lado1 = lado1;
	}

	public double getLado2() {
		return lado2;
	}

	public void setLado2(double lado2) {
		this.lado2 = lado2;
	}

	public double getLado3() {
		return lado3;
	}

	public void setLado3(double lado3) {
		this.lado3 = lado3;
	}

	public double getLado4() {
		return lado4;
	}

	public void setLado4(double lado4) {
		this.lado4 = lado4;
	}
	
	public double getPerimetro() {
		return perimetro;
	}
	
	public void setPerimetro(double perimetro) {
		this.perimetro = perimetro;
	}
	
	public double getArea() {
		return area;
	}
	
	public void setArea(double area) {
		this.area = area;
	}


}
