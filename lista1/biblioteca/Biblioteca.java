package PooPggq.lista1.biblioteca;

import java.util.ArrayList;

public class Biblioteca {
	private String nome, local;
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
		return getAcervo();
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
			System.out.println((i+1) + "° livro: ");
			System.out.println("Titulo: " + acervo.get(i).getTitulo());
			System.out.println("Autor:  "+ acervo.get(i).getAutor());
		}
	
	}
	
	public void cadastrarLivro(String titulo, String autor) {
		Livro novoLivro = new Livro(titulo, autor);
		this.setAcervo(novoLivro);
	}
}





















