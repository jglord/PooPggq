package PooPggq.lista1.banco;

public class ContaPoupanca extends ContaBancaria{
	private int diaDeRendimento;
	private double taxaDeRendimento;
	
	public ContaPoupanca(String nomeCliente, double saldo, int diaDeRendimento, double taxaDeRendimento) {
		super(nomeCliente, saldo);
		this.setDiaDeRendimento(diaDeRendimento);
		this.setTaxaDeRendimento(taxaDeRendimento);
	}
	
	public int getDiaDeRendimento() {
		return diaDeRendimento;
	}

	public void setDiaDeRendimento(int diaDeRendimento) {
		if(diaDeRendimento > 0 & diaDeRendimento <= 31) {
			this.diaDeRendimento = diaDeRendimento;
		}
		else {
			System.out.println("Dia inválido!");
		}
		
	}

	public double getTaxaDeRendimento() {
		return taxaDeRendimento;
	}

	public void setTaxaDeRendimento(double taxaDeRendimento) {
		if( taxaDeRendimento > 0 && taxaDeRendimento <= 1.0 ) {
			this.taxaDeRendimento = taxaDeRendimento;
		}
		else {
			System.out.println("Não é possível ter uma taxa de rendimento acima de 100%!");
		}
	}
	
	
	// Duas alternativas, perguntar qual a melhor ao monitor.
	public double calcularNovoSaldo() {
		
		double novoSaldo = getSaldo() + ( getSaldo() * getTaxaDeRendimento() );
		
		return novoSaldo;
	}
	
	public boolean calcularNovoSaldoDia(int diaDeRendimento) {
		
		if( this.getDiaDeRendimento() == diaDeRendimento ) {
			double novoSaldo = getSaldo() + ( getSaldo() * getTaxaDeRendimento() );
			setSaldo(novoSaldo);			
			
			return true;
		}
		else {
			System.out.println("Ainda não está no dia certo para o rendimento!");
			return false;
		}
	}

	
	public static void main(String[] args) {

		ContaPoupanca conta1 = new ContaPoupanca("João", 1000, 25, 0.08);
		
		System.out.println("Saldo inicial de Leyvino: " + conta1.getSaldo());
		
		conta1.sacar(235.50);
		System.out.println("\nSacando 235.50 da conta..." );
		System.out.println("Saldo final de " + conta1.getNomeCliente() + " " + conta1.getSaldo());	
		
		conta1.depositar(5.5);
		System.out.println("Saldo apos deposito " + conta1.getSaldo());	
		
		System.out.println("\n\nTestando calcularNovoSaldoDia com um dia errado(18)...");		
		conta1.calcularNovoSaldoDia(18);
		System.out.println("Saldo apos primeiro teste = " + conta1.getSaldo());
		
		System.out.println("\nAgora testando com o dia correto(25)");
		conta1.calcularNovoSaldoDia(25);
		System.out.println("Saldo apos segundo teste = " + conta1.getSaldo());
		
	}
	
	
}
