package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3.questao3;

public class Quadrado extends Quadrilatero {

	public Quadrado(double lado) {
		super();
		this.setLado1(lado);
	}
	
	public void calcularArea() { 
		setArea(this.getLado1() * this.getLado1()); 
	}
	
	@Override
	public void calcularPerimetro() {
		this.setPerimetro(getLado1()*4);
	}


}
