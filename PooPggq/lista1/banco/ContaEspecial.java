package UfersaCC.PooPggq.lista1.banco;

public class ContaEspecial extends ContaBancaria{

	private double limite;
	
	public ContaEspecial(String nomeCliente, double saldo, double limite) {
		super(nomeCliente, saldo);
		
	}

	public double getLimite() {
		return limite;
	}

	public void setLimite(double limite) {
		if(limite > 0) {
			this.limite = limite;
		}
		else {
			System.out.println("Valor inválido para o limite da conta de");
		}
	}
	
	public void setSaldo() {
		if(  )
	}
	
	public boolean sacar(double valorSaque) {
		
		if( getSaldo() - valorSaque > getLimite() ) {
			
		}
		
		return true;
	}
	
}
