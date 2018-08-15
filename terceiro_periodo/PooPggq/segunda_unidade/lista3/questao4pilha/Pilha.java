package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3.questao4pilha;

public class Pilha {
    private int topo = -1;
    private int array[] = new int[3];
    private final int TAM = 3;

    public static void main(String[] args) {

        Pilha p = new Pilha();

        var i = 10.0;

        p.pop();

        p.push(10);
        p.push(35);
        p.push(40);
        p.push(22);

        System.out.println("Percorrendo antes de remover um elemento da pilha...");
        p.percorrer();

        p.pop();
        System.out.println("\nApós remover um elemento...");
        p.percorrer();

    }


    public boolean push(int valor) {
        // Inserindo primeiro elemento na pilha
        if ( this.getTopo() == TAM-1) {
            System.out.println("ERRO! Pilha cheia.");
            return false;
        }
        else
        {
            this.setTopo('+'); // Incrementa o topo da pilha
            this.array[this.getTopo()] = valor;

        }
        return true;
    }

    public int pop() {
        int retornado;

        if(this.getTopo() == -1)
        {
            System.out.println("Pilha vazia, insira elementos");
            return 0;
        }
        else {
            retornado = this.array[ getTopo() ];
            this.setTopo('-');
        }
        return retornado;
    }

    public void percorrer() {
        for (int i = 0; i <= this.getTopo(); i++) {
            System.out.println("Posicao" + i + ": " + this.getArray()[i]);
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

    public int[] getArray() {
        return array;
    }

    public void setArray(int[] array) {
        this.array = array;
    }

    public int getTAM() {
        return TAM;
    }


}
