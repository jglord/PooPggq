package UfersaCC.terceiro_periodo.PooPggq.segunda_unidade.lista3;

public class Produto {
    private String nomeLoja;
    private double preco;

    public String getNomeLoja() {
        return nomeLoja;
    }

    public void setNomeLoja(String nomeLoja) {
        if(!nomeLoja.isEmpty()){
            this.nomeLoja = nomeLoja;
        }
        else {
            System.out.println("Valor inválido");
        }
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        if(preco > 0) {
            this.preco = preco;
        }
        else {
            System.out.println("Valor inválido");
        }
    }
}
