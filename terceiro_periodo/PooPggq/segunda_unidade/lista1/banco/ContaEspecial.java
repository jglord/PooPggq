package UfersaCC.PooPggq.lista1.banco;

public class ContaEspecial extends ContaBancaria{

	private double limite;
	
	public ContaEspecial(String nomeCliente, double saldo, double limite) {
		super(nomeCliente, saldo);
		setLimite(limite);
	}

	public double getLimite() {
		return limite;
	}

	public void setLimite(double limite) {
		if(limite > 0) {
			this.limite = limite;
		}
		else {
			System.out.println("Valor inv�lido para o limite da conta de");
		}
	}
	
	public void setSaldo(double saldo) {
		
		if( saldo >= -limite ) {
			this.saldo = saldo;
		} 
		else {
			System.out.println("Limite ultrapassado!");
		}	
	}
	
	public boolean sacar(double valorSaque) {
		
		double valorMaximoSaque = this.getSaldo() + this.limite;
		
		if( valorSaque <= valorMaximoSaque ) {
			System.out.println("Saque realizado com sucesso!");
			
			setSaldo(this.getSaldo() - valorSaque);
		}
		else {
			System.out.println("Não é possível sacar esse valor!");
			return false;
		}
		
		return true;
	}
}
