package UfersaCC.PooPggq.lista1.banco;

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
	
	
//	// Duas alternativas, perguntar qual a melhor ao monitor.
//	public double calcularNovoSaldo() {
//		
//		double novoSaldo = getSaldo() + ( getSaldo() * getTaxaDeRendimento() );
//		
//		return novoSaldo;
//	}
	
	public boolean calcularNovoSaldo(int diaDeRendimento) {
		
		if( this.getDiaDeRendimento() == diaDeRendimento ) {
			
			System.out.println("Conta teve rendimento com sucesso!");
			
			double novoSaldo = getSaldo() + ( getSaldo() * getTaxaDeRendimento() );
			setSaldo(novoSaldo);			
			
			return true;
		}
		else {
			System.out.println("Ainda não está no dia certo para o rendimento!");
			return false;
		}
	}
	
}
