package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3.questao3;

public class Circulo implements FormaGeometrica{
	private double raio;
	private double perimetro, area;

	@Override
	public void calcularArea() {
		double area = 3.14159 * (this.getRaio() * this.getRaio());
		this.setArea(area);
	}

	@Override
	public void calcularPerimetro() {
		double comprimento = (2 * 3.14159) * getRaio();
		this.setPerimetro(comprimento);
	}
	
	public double getRaio() {
		return raio;
	}
		
	public void setRaio(double raio) {
		this.raio = raio;
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
	
	public Circulo(double raio) {
		super();
		setRaio(raio);
	}
}
