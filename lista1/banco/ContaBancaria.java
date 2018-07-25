package PooPggq.lista1.banco;

public class ContaBancaria {

	private static int numeroConta = 0;
	private float saldo;
	private String nomeCliente;
	
	// Construtor
	public ContaBancaria(String nomeCliente) {
		this.setNomeCliente(nomeCliente);
		this.setNumeroConta();
	}
	
	public int getNumeroConta() {
		return numeroConta;
	}
	
	public void setNumeroConta() {
		numeroConta++;
	}
	
	public float getSaldo() {
		return saldo;
	}
	
	public void setSaldo(float saldo) {
		if(saldo > 0) {
			this.saldo = saldo;
		}
		else {
			System.out.println("Saldo negativo não existe");
		}
	}
	
	public String getNomeCliente() {
		return nomeCliente;
	}
	
	public void setNomeCliente(String nomeCliente) {
		if( !nomeCliente.isEmpty() ) {
			this.nomeCliente = nomeCliente;
		}
		else {
			System.out.println("Nomé inválido!");
		}
	}
	
	public boolean sacar(float valor) {
		
		if( valor < getSaldo() && valor > 0 ) {
			System.out.println("Saque realizado com sucesso!");
			
			float novoSaldo = getSaldo() - valor;
			setSaldo(novoSaldo);
		}
		
		return true;
	}
	
	
	public static void main(String[] args) {
		ContaBancaria conta1 = new ContaBancaria("Leyvino");
		conta1.setSaldo(125000.0f);
		
		System.out.println("Saldo inicial de Leyvino: " + conta1.getSaldo());
		
		conta1.sacar(235.50f);
		System.out.println("\nSacando 235.50 da conta..." );
		System.out.println("Saldo final de Leyvino: " + conta1.getSaldo());	
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
