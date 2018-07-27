package UfersaCC.PooPggq.lista1.banco;

public class ContaBancaria {

	protected static int numeroConta = 0;
	protected double saldo;
	protected String nomeCliente;
	
	
	// Construtor
	public ContaBancaria(String nomeCliente, double saldo) {
		this.setNomeCliente(nomeCliente);
		this.setSaldo(saldo);
		this.setNumeroConta();
	}
	
	public static int getNumeroConta() {
		return numeroConta;
	}
	
	public void setNumeroConta() {
		numeroConta++;
	}
	
	public double getSaldo() {
		return this.saldo;
	}
	
	public void setSaldo(double saldo) {
		if(saldo > 0) {
			this.saldo = saldo;
		}
		else {
			System.out.println("Saldo negativo n�o � poss�vel");
		}
	}
	
	public String getNomeCliente() {
		return this.nomeCliente;
	}
	
	public void setNomeCliente(String nomeCliente) {
		if( !nomeCliente.isEmpty() ) {
			this.nomeCliente = nomeCliente;
		}
		else {
			System.out.println("Nome inválido!");
		}
	}
	
	public boolean sacar(double valorSaque) {
		
		if( valorSaque < getSaldo() && valorSaque > 0 ) {
			System.out.println("Saque realizado com sucesso!");
			
			this.setSaldo(this.getSaldo() - valorSaque);
		}
		else {
			System.out.println("Não é possível sacar esse valor!");
			return false;
		}
		
		return true;
	}
	
	public boolean depositar(double valorDeposito) {
		if( valorDeposito > 0 ) {
			System.out.println("Deposito realizado com sucesso!");
			this.setSaldo(this.getSaldo() + valorDeposito);			
		}
		else {
			System.out.println("Valor inválido para depósito!");
		}
		
		return true;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
