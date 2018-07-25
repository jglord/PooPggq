package PooPggq.lista1.biblioteca;

import java.util.ArrayList;

public class Biblioteca {
	private String nome, local;
	// private LibUser user = new LibUser();
	private ArrayList<Livro> acervo = new ArrayList<Livro>();
	
	
	public Biblioteca(String nome, String local) {
		this.nome = nome;
		this.local = local;
	}
	
		
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		if(!nome.isEmpty()) {
			this.nome = nome;
		}
	}
	
	public String getLocal() {
		return local;
	}
	
	public void setLocal(String local) {
		if(!local.isEmpty()) {
			this.local = local;
		}
	}
	
	public ArrayList<Livro> getAcervo() {
		return acervo;
	}
	
	public void setAcervo(Livro livro) {
		if(acervo.size() < 150) {
			this.acervo.add(livro);
		}
		else {
			System.out.println("Capacidade maxima da biblioteca atingida!");
		}
	}
	
	public void showAcervo() {
		for(int i = 0; i < acervo.size(); i++ ) {
			System.out.println("\nLivro " + (i+1) + " - " + acervo.get(i).isStatus());
			System.out.println("Titulo: " + acervo.get(i).getTitulo());
			System.out.println("Autor:  "+ acervo.get(i).getAutor());
			System.out.println();
		}
	
	}
	
	public void cadastrarLivro(String titulo, String autor,int quantPaginas) {
		Livro novoLivro = new Livro(titulo, autor, quantPaginas);
		this.setAcervo(novoLivro);
	}
	
	
	public void mostraOpcoes() {
		
		System.out.println("- - - - - - - - - - - - - - - - - - - - - - - - ");
		System.out.println("Fun��es do bibliotec�rio");
		System.out.println("1 - Adicionar novo livro ao acervo.");
		System.out.println("2 - Consultar acervo da biblioteca.");
		System.out.println("- - - - - - - - - - - - - - - - - - - - - - - - ");
		System.out.println("Fun��es do usuario");
		System.out.println("3 - Pegar livro emprestado.");
		System.out.println("4 - Devolver livro.");
		System.out.println("5 - Consultar livros emprestados ao usuario.");
		System.out.println("0 - Sair do programa.");
		System.out.println("- - - - - - - - - - - - - - - - - - - - - - - - ");

		
	}
	
	// Metodo para devolver um livro que foi emprestado ao usuario da biblioteca
	public boolean devolverLivro(LibUser user, int opcaoDevolver) {
	
		if( opcaoDevolver < user.getEmprestados().size() ){
			user.getEmprestados().remove(opcaoDevolver);
			System.out.println("Livro devolvido com sucesso!");
		}
		else {
			System.out.println("Livro selecionado n�o existe nos emprestados de " + user.getNome() + "!!");
			return false;
		}
		
		return true;
	
	}
	
	// Metodo para pegar um livro emprestado e adicionar ele a lista de emprestados do usuario da biblioteca
	public boolean emprestarLivro(LibUser user, int opcaoEmprestado) {
		
		if( getAcervo().get(opcaoEmprestado).isStatus().equalsIgnoreCase("Disponivel") ) {
			 
			 //  Setando o livro para "emprestado" e depois adicionando o livro
			 //  ao ArrayList dos livros emprestados do usuario.
			
			System.out.println("Livro emprestado com sucesso!");
			getAcervo().get(opcaoEmprestado).setStatus("Emprestado");
			user.getEmprestados().add( getAcervo().get(opcaoEmprestado) );
		}
		else {
			System.out.println("Livro solicitado indispon�vel para empr�stimo, escolha outra opera��o.");
			return false;
		}
		
		return true;
	}
	
	
	
}





















