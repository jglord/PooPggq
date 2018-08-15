package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3.questao3;

public class Retangulo extends Quadrilatero {

	public Retangulo(double base, double altura) {
		super();
		this.setLado1(base);
		this.setLado2(altura);
	}

	@Override
	public void calcularArea() {
		setArea(this.getLado1() * this.getLado2());
	}
}
