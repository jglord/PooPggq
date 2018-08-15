package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3.questao4pilha;

import java.util.ArrayList;

public class Pilha <T> {
	T objeto;
    private int topo = -1;
    private final int TAM = 3;
    private ArrayList<T> pilha = new ArrayList<T>();
    
    public static void main(String[] args) {

        Pilha<String> p = new Pilha<String>();

       // p.pop();

        p.push("oi");
        p.push("ola");
        p.push("alo");
        p.push("hey");

        System.out.println("Percorrendo antes de remover um elemento da pilha...");
        p.percorrer();

        p.pop();
        System.out.println("\nApós remover um elemento...");
        p.percorrer();

    }


    public boolean push(T Objeto) {
        // Inserindo primeiro elemento na pilha
        if ( this.getTopo() == TAM-1) {
            System.out.println("ERRO! Pilha cheia.");
            return false;
        }
        else
        {
            this.setTopo('+'); // Incrementa o topo da pilha
            this.pilha.add(this.getTopo(), Objeto);
        }
        return true;
    }

    public T getObjeto() {
		return objeto;
	}


	public void setObjeto(T objeto) {
		this.objeto = objeto;
	}


	public T pop() {
        T retornado;

//        if(this.getTopo() == -1)
//        {
//            System.out.println("Pilha vazia, insira elementos");
//            return ;
//        }
//        else
//        {
            retornado = this.pilha.get(this.getTopo());
            this.setTopo('-');
//        }
        return retornado;
    }

    public void percorrer() {
        for (int i = 0; i <= this.getTopo(); i++) {
            System.out.println("Posicao" + i + ": " + this.getPilha().get(i));
        }
    }

    public int getTopo() {
        return topo;
    }

    // Define se incrementa ou decrementa o topo
    public void setTopo(char operador) {
        if(operador == '+'){
            this.topo++;
        }
        else if(operador =='-'){
            this.topo--;
        }
    }

    public ArrayList<T> getPilha() {
		return pilha;
	}


	public void setPilha(ArrayList<T> pilha) {
		this.pilha = pilha;
	}


	public void setTopo(int topo) {
		this.topo = topo;
	}


	public int getTAM() {
        return TAM;
    }


}
