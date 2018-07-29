package UfersaCC.PooPggq.lista1.banco;

import java.util.Scanner;

public class Banco {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in); 
		
		System.out.println("======BANCO UFERSA======");
		System.out.print("Informe seu nome: ");
		String nomeCliente = in.next();
		
		
		System.out.println("Escolha umas das três opções de conta abaixo:");

		System.out.println("1)|Conta simples| 2)|Conta especial| 3)|Conta poupança|");
		System.out.print("Opção: ");
		int opcaoConta = in.nextInt();
		
		System.out.println("Você começa com R$1000.00 de saldo.");
		
		switch (opcaoConta) {
		case 1:	
			System.out.println("=====Conta Normal=====");
			ContaBancaria conta1 = new ContaBancaria(nomeCliente, 1000);
			
			usarContaBancaria(conta1);
			
			break;
			
		case 2:
			System.out.println("=====Conta Especial=====");
			System.out.println("Informe o limite da sua conta:");
			double limite = in.nextDouble();
			
			ContaEspecial conta2 = new ContaEspecial(nomeCliente, 1000, limite);
			
			usarContaEspecial(conta2);
			
			break;
		case 3:
			System.out.println("=====Conta Poupança=====");
			System.out.print("Dia de rendimento: ");
			int diaDeRendimento = in.nextInt();
			
			System.out.print("Taxa de rendimento: ");
			double taxaDeRendimento = in.nextDouble();
			
			taxaDeRendimento = taxaDeRendimento / 100;			
			
			ContaPoupanca conta3 = new ContaPoupanca(nomeCliente, 1000, diaDeRendimento, taxaDeRendimento);			
			
			usarContaPoupanca(conta3);
			
			break;
			
		default:
			break;
		}
		System.out.println("Banco finalizado!");
		
		in.close();
	}
	
	public static void usarContaBancaria(ContaBancaria conta) {
		
		Scanner in = new Scanner(System.in);
		int opcao;
		
		System.out.println("\nDono da conta: " + conta.getNomeCliente());
		System.out.println("Numero da conta: " + conta.getNumeroConta());
		
		do {
			
			
			
			System.out.println("\n===Operações===");
			System.out.println("1 - Sacar");
			System.out.println("2 - Depositar");
			System.out.println("3 - Consultar saldo");
			System.out.println("0 - Sair");
			
			opcao = in.nextInt();
			
			switch(opcao) {
			
			case 1:
				System.out.printf("Saldo: R$ %.2f", conta.getSaldo());
				System.out.println("\nValor do saque: ");
				double valorSaque = in.nextDouble();
				
				conta.sacar(valorSaque);
				
				break;
				
			case 2:
				System.out.println("Valor do depósito: ");
				double valorDeposito = in.nextDouble();
				
				conta.depositar(valorDeposito);
				break;
			
			case 3:
				System.out.printf("Seu saldo atual é R$%.2f", conta.getSaldo());
				break;
			
			default:
				break;
			}
			
		}while(opcao != 0);
		
		in.close();		
	}
	
	public static void usarContaEspecial(ContaEspecial conta) {
		
		Scanner in = new Scanner(System.in);
		int opcao;
		
		System.out.println("\nDono da conta: " + conta.getNomeCliente());
		System.out.println("Numero da conta: " + conta.getNumeroConta());
		
		do {
			
			System.out.println("\n===Operações===");
			System.out.println("1 - Sacar");
			System.out.println("2 - Depositar");
			System.out.println("3 - Consultar saldo");
			System.out.println("4 - Consultar limite:");
			System.out.println("0 - Sair");

			opcao = in.nextInt();
			
			switch(opcao) {
			
			case 1:
				System.out.printf("Saldo: R$%.2f", conta.getSaldo());
				System.out.printf("\nLimite: R$%.2f", conta.getLimite());
				System.out.println("\nValor do saque: ");
				double valorSaque = in.nextDouble();
				
				conta.sacar(valorSaque);
				
				break;
				
			case 2:
				System.out.println("Valor do depósito: ");
				double valorDeposito = in.nextDouble();
				
				conta.depositar(valorDeposito);
				break;
			
			case 3:
				System.out.printf("Seu saldo atual é R$%.2f", conta.getSaldo());
				break;
				
			case 4:
				System.out.printf("O limite da conta é R$%.2f", conta.getLimite());
				break;
			
			default:
				break;
			}
			
		}while(opcao != 0);
		
		in.close();		
	}

	public static void usarContaPoupanca(ContaPoupanca conta) {
		Scanner in = new Scanner(System.in);
		int opcao;
		
		System.out.println("\nDono da conta: " + conta.getNomeCliente());
		System.out.println("Taxa de rendimento: " + conta.getTaxaDeRendimento() * 100 + "%");
		System.out.println("Dia de rendimento: " + conta.getDiaDeRendimento());			
		System.out.println("Numero da conta: " + conta.getNumeroConta());
		
		do {			
			
			System.out.println("\n===Operações===");
			System.out.println("1 - Sacar");
			System.out.println("2 - Depositar");
			System.out.println("3 - Consultar saldo");
			System.out.println("4 - Render a conta");
			System.out.println("0 - Sair");

			opcao = in.nextInt();
			
			switch(opcao) {
			
			case 1:
				System.out.printf("Saldo: R$ %.2f", conta.getSaldo());
				System.out.println("\nValor do saque: ");
				double valorSaque = in.nextDouble();
				
				conta.sacar(valorSaque);
				
				break;
				
			case 2:
				System.out.println("Valor do depósito: ");
				double valorDeposito = in.nextDouble();
				
				conta.depositar(valorDeposito);
				break;
			
			case 3:
				System.out.printf("Seu saldo atual é R$ %.2f", conta.getSaldo());
				break;
				
			case 4:
				System.out.println("Informe a data de hoje: ");
				int diaDeRendimento = in.nextInt();
				
				conta.calcularNovoSaldoDia(diaDeRendimento);
				
				break;
			
			default:
				break;
			}
			
		}while(opcao != 0);
		
		in.close();		
	}

}
















