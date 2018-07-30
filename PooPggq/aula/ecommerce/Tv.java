package UfersaCC.PooPggq.aula.ecommerce;

public class Tv {
	private String qualidadeDaImagem;
	private double tamanhoDaTela;
	
	public String getQualidadeDaImagem() {
		return qualidadeDaImagem;
	}
	
	public void setQualidadeDaImagem(String qualidadeDaImagem) {
		if(!qualidadeDaImagem.isEmpty()) {
			this.qualidadeDaImagem = qualidadeDaImagem;
		}
		else {
			System.out.println("Campo vazio!");
		}
	}
	
	public double getTamanhoDaTela() {
		return tamanhoDaTela;
	}
	
	public void setTamanhoDaTela(double tamanhoDaTela) {
		if(tamanhoDaTela > 0) {
			this.tamanhoDaTela = tamanhoDaTela;
		} else {
			System.out.println("Tamanho negativo");
		}
}
