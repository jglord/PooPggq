package UfersaCC.PooPggq.lista1.biblioteca;

import java.util.ArrayList;
import java.util.Scanner;

public class LibUser {
	private String nome;
	private ArrayList<Livro> emprestados = new ArrayList<Livro>();
	
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		Biblioteca biblioteca = new Biblioteca("Orlando teixeira", "Campus Mossoró"); // Nome e local
		
		System.out.print("Informe o nome do usu�rio da biblioteca: ");
		String nome = in.nextLine();
		
		LibUser user = new LibUser();
		user.setNome(nome);
		
		int opcao;
		do {
			System.out.println("\nBiblioteca " + biblioteca.getNome());
			System.out.println("Localizada em " + biblioteca.getLocal());
			
			biblioteca.mostraOpcoes();
			System.out.print("Escolha uma op��o:");
			opcao = in.nextInt();
			
			switch (opcao) {

			case 1:		// Cadastra livro no acervo
				
				in.nextLine();
				String titulo, autor;
				int quantPaginas;
				
				System.out.print("Titulo do livro: ");
				titulo = in.nextLine();
				System.out.print("Autor do livro: ");
				autor = in.nextLine();
				System.out.print("Quantidade de p�ginas do livro:");
				quantPaginas = in.nextInt();
				
				biblioteca.cadastrarLivro(titulo, autor, quantPaginas);
				
				break;
				
			case 2:	 // Mostra o acervo da biblioteca.
				
				biblioteca.showAcervo();

				break;		
			
			case 3:		// Pega algum livro emprestado
				
				if( biblioteca.getAcervo().size() != 0 ) {
					
					biblioteca.showAcervo();
					
					System.out.print("Escolha um livro para pegar emprestado: ");
					int opcaoEmprestado = in.nextInt();
					
					biblioteca.emprestarLivro( user, opcaoEmprestado-1);
				}
				else {
					System.out.println("Acervo da biblioteca vazio, espere a biblioteca adicionar novos livros!");
				}
				
				break;
		
			case 4:		// Devolver livro
				
				if( user.mostrarEmprestados(user) ) { 
					
					System.out.print("Escolha um livro para devolver: ");
					int opcaoDevolver = in.nextInt();
					
					biblioteca.devolverLivro(user, opcaoDevolver-1);
				}
				
				break;
			
			case 5:		// Mostra livros emprestados ao usuario
				user.mostrarEmprestados(user);
				
				break;
			
			default:
				break;
			}
			
			
		} while (opcao != 0);
		in.close();
		System.out.println("Programa finalizado!!!");
		
	}


	public ArrayList<Livro> getEmprestados() {
		return emprestados;
	}

	// Número maximo de emprestimos é 4 livros por usuário
	public void setEmprestados(ArrayList<Livro> emprestados) {
		if(emprestados.size() == 4) {
			this.emprestados = emprestados;
		}
		else {
			System.out.println("Quantidade maxima de 4 livros por pessoa atingida!");
		}
	}
	
	

	public String getNome() {
		return nome;
	}


	public void setNome(String nome) {
		if(!nome.isEmpty()) {
			this.nome = nome;
		}
	}
	
	public boolean mostrarEmprestados(LibUser user) {
		
		if(user.getEmprestados().size() != 0){
			System.out.println("Lista de livros emprestados a " + user.getNome());
			for( int i = 0; i < user.getEmprestados().size(); i++ ) {
				System.out.println("Livro " + (i+1) + ": ");
				System.out.println("Titulo: " + user.getEmprestados().get(i).getTitulo());
				System.out.println("Autor: " + user.getEmprestados().get(i).getAutor());
				System.out.println();
			}
		}
		else {
			System.out.println("Voc� n�o pegou nenhum livro emprestado.");
			return false;
		}

		return true;
	}
	
}
