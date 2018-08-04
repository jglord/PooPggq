package UfersaCC.PooPggq.aula.ecommerce;

public class Celular extends Produto{
	private double tamanhoDaTela;
	private int quantidadeDeChips;
	
	public double getTamanhoDaTela() {
		return tamanhoDaTela;
	}
	
	public void setTamanhoDaTela(double tamanhoDaTela) {
		if(tamanhoDaTela > 0 ) {
			this.tamanhoDaTela = tamanhoDaTela;
		}
		else {
			System.out.println("Tamanho negativo nao existe!");
		}
	}
	
	public int getQuantidadeDeChips() {
		return quantidadeDeChips;
	}
	
	public void setQuantidadeDeChips(int quantidadeDeChips) {
		if(quantidadeDeChips >= 1) {
			this.quantidadeDeChips = quantidadeDeChips;
		}
		else {
			System.out.println("Quantidade de chips negativa nao pode!");
		}
	}
}
