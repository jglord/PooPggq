package UfersaCC.PooPggq.aula.ecommerce;


class Produto {
    private String nome, marca, modelo;
    private int preco;

    public void setNome(String nome) {
        if(!nome.isEmpty()){
            this.nome = nome;
        } 
        else {  
            System.out.println("Nome vazio!");
        }
    }

    public String getNome() {
        return nome;
    }

    public void setmMarca(String marca) {
        if(!marca.isEmpty()){
            this.marca = marca;
        } 
        else {  
            System.out.println("Marca vazia!");
        }
    }

    public String getMarca() {
        return marca;
    }

    public void setModelo(String modelo) {
        if(!modelo.isEmpty()){
            this.modelo = modelo;
        } 
        else {  
            System.out.println("Nome vazio!");
        }
    }

    public String getModelo() {
        return modelo;
    }

    
    public void setPreco(int preco) {
        if(preco > 0) {
            this.preco = preco;
        }
        else {
        	System.out.println("Preço negativo nao existe!");
        }
    }

    public int getPreco() {
        return preco;
    }

}