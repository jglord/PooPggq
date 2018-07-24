package segundaUnidade.PooPggq.lista1.biblioteca;

import java.util.ArrayList;
import java.util.Scanner;

import javax.sound.midi.Soundbank;

import com.sun.glass.ui.TouchInputSupport;

public class Usuario {
	private ArrayList<Livro> emprestados = new ArrayList<Livro>();
	
	
	public static void main(String[] args) {
		Biblioteca biblioteca = new Biblioteca("Orlando teixeira", "Campus Mossoró");
		Scanner in = new Scanner(System.in);
		
		int opcao;
		do {
			System.out.println("\nBiblioteca " + biblioteca.getNome());
			System.out.println("Localizada em " + biblioteca.getLocal());
			
			mostraOpcoes();
			
			opcao = in.nextInt();
			
			switch (opcao) {
			case 1:
				biblioteca.showAcervo();
								
				break;
			case 2:
				break;
			
			case 3:
				String titulo, autor;
				
				System.out.println("Título do livro: ");
				titulo = in.nextLine();
				System.out.println("Autor do livro: ");
				autor = in.nextLine();
				
				Livro novoLivro = new Livro(titulo, autor);
				
				biblioteca.setAcervo(novoLivro);				
				
			default:
				break;
			}
			
			
			
		} while (opcao != 0);
		
		
		
	}	
	
	public static void mostraOpcoes() {
		System.out.println("1 - Pegar livro emprestado!");
		System.out.println("2 - Devolver livro");
		System.out.println("3 - Adicionar novo livro ao acervo");
		System.out.println("4 - Consultar acervo da biblioteca");
		System.out.println("0 - Sair do programa");
	}

}
