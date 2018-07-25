package PooPggq.lista1.biblioteca;

import java.util.ArrayList;
import java.util.Scanner;

public class LibUser {
	private String nome;
	private ArrayList<Livro> emprestados = new ArrayList<Livro>();
	
	public LibUser(String nome) {
		this.nome = nome;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		Biblioteca biblioteca = new Biblioteca("Orlando teixeira", "Campus MossorÃ³"); // Nome e local
		
		System.out.print("Informe o nome do usuário da biblioteca: ");
		String nome = in.nextLine();
		
		LibUser user = new LibUser(nome);
		
		int opcao;
		do {
			System.out.println("\nBiblioteca " + biblioteca.getNome());
			System.out.println("Localizada em " + biblioteca.getLocal());
			
			mostraOpcoes();
			System.out.print("Escolha uma opção:");
			opcao = in.nextInt();
			
			switch (opcao) {

			case 1:		// Cadastra livro no acervo
				
				in.nextLine();
				String titulo, autor;
				
				System.out.print("Titulo do livro: ");
				titulo = in.nextLine();
				System.out.print("Autor do livro: ");
				autor = in.nextLine();
				
				biblioteca.cadastrarLivro(titulo, autor);
				
				break;
				
			case 2:	 // Mostra o acervo da biblioteca.
				
				biblioteca.showAcervo();

				break;		
			
			case 3:		// Pega algum livro emprestado
				
				if( biblioteca.getAcervo().size() != 0 ) {
					
					biblioteca.showAcervo();
					
					System.out.print("Escolha um livro para pegar emprestado: ");
					int opcaoEmprestado = in.nextInt();
					
					pegarEmprestado(biblioteca, user, opcaoEmprestado-1);
				}
				else {
					System.out.println("Acervo da biblioteca vazio, espere a biblioteca adicionar novos livros!");
				}
				
				break;
		
			case 4:		// Devolver livro
				
				if( user.mostrarEmprestados(user) ) { 
					
					System.out.print("Escolha um livro para devolver: ");
					int opcaoDevolver = in.nextInt();
					
					devolverLivro(user, opcaoDevolver-1);
				}
				
				break;
			
			case 5:
				user.mostrarEmprestados(user);
				
				break;

			default:
				break;
			}
			
			
		} while (opcao != 0);
		in.close();
		System.out.println("Programa finalizado!!!");
		
	}	
	
	public static void mostraOpcoes() {
		
		System.out.println("- - - - - - - - - - - - - - - - - - - - - - - - ");
		System.out.println("Funções do bibliotecário");
		System.out.println("1 - Adicionar novo livro ao acervo.");
		System.out.println("2 - Consultar acervo da biblioteca.");
		System.out.println("- - - - - - - - - - - - - - - - - - - - - - - - ");
		System.out.println("Funções do usuario");
		System.out.println("3 - Pegar livro emprestado.");
		System.out.println("4 - Devolver livro.");
		System.out.println("5 - Consultar livros emprestados ao usuario.");
		System.out.println("0 - Sair do programa.");
		System.out.println("- - - - - - - - - - - - - - - - - - - - - - - - ");

		
	}
	
	// Metodo para devolver um livro que foi emprestado ao usuario da biblioteca
	public static boolean devolverLivro(LibUser user, int opcaoDevolver) {
	
		if( opcaoDevolver < user.emprestados.size() ){
			user.emprestados.remove(opcaoDevolver);
			System.out.println("Livro devolvido com sucesso!");
		}
		else {
			System.out.println("Livro selecionado não existe nos emprestados de " + user.nome + "!!");
			return false;
		}
		
		return true;
	
	}
	
	// Metodo para pegar um livro emprestado e adicionar ele a lista de emprestados do usuario da biblioteca
	public static boolean pegarEmprestado(Biblioteca biblioteca,LibUser user, int opcaoEmprestado) {
		
		if( biblioteca.getAcervo().get(opcaoEmprestado).isStatus().equalsIgnoreCase("Disponivel") ) {
			 
			 //  Setando o livro para "emprestado" e depois adicionando o livro
			 //  ao ArrayList dos livros emprestados do usuario.
			
			System.out.println("Livro emprestado com sucesso!");
			biblioteca.getAcervo().get(opcaoEmprestado).setStatus("Emprestado");
			user.emprestados.add( biblioteca.getAcervo().get(opcaoEmprestado) );
		}
		else {
			System.out.println("Livro solicitado indisponível para empréstimo, escolha outra operação.");
			return false;
		}
		
		return true;
	}
	
	public boolean mostrarEmprestados(LibUser user) {
		
		if(user.emprestados.size() != 0){
			for( int i = 0; i < user.emprestados.size(); i++ ) {
				System.out.println("Lista de livros emprestados a " + user.nome);
				System.out.println("Livro " + (i+1) + ": ");
				System.out.println("Titulo: " + user.emprestados.get(i).getTitulo());
				System.out.println("Autor: " + user.emprestados.get(i).getAutor());
				System.out.println();
			}
		}
		else {
			System.out.println("Você não pegou nenhum livro emprestado.");
			return false;
		}

		return true;
	}

}
