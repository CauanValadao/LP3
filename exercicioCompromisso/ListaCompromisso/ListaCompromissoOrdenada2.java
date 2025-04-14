package exercicioCompromisso.ListaCompromisso;
import exercicioData.*;

public class ListaCompromissoOrdenada2 {
    private Data[] lista;
    private int tam = 0;

    public ListaCompromissoOrdenada2(int capacidade){
        lista = new Data[capacidade];
        //for(int i = 0; i < capacidade; i++) 
         //   lista[i] = new Data();
    }

    public ListaCompromissoOrdenada2(){
        lista = new Data[10];
    }

    public boolean verificaCompromisso(Data data){
        if(data.igualA(lista[buscaIndice(data)])) return true;
        return false;
    }

    public boolean adicionaCompromisso(Data novaData){
        if(this.tam == 0){
            lista[tam++] = novaData;
            return true;
        }

        int indice = buscaIndice(novaData);
        if(this.tam < lista.length && indice == this.tam){
            lista[tam++] = novaData;
            return true;
        }
        
        if(this.tam >= lista.length || novaData.igualA(lista[indice])) return false;
        
        for(int i = this.tam; i > indice; i--)
            lista[i] = lista[i-1];

        lista[indice] = novaData;
        tam++;
        return true;
    }

    public boolean desmarcaCompromisso(Data data){
        int indice = buscaIndice(data);
        if(data.diferenteDe(lista[indice]) || this.tam == 0) return false;

        for(int i = indice; i < this.tam -1; i++)
            lista[i] = lista[i+1];
        
        tam--;
        return true;
    }

    private int buscaIndice(Data data){
        return buscaBinaria(data, 0, tam - 1);  
    }

    private int buscaBinaria(Data data, int esquerda, int direita){
        if(esquerda > direita)
            return esquerda;
        
        int meio = (esquerda + direita) / 2;

        if(data.anteriorA(lista[meio])) return buscaBinaria(data, esquerda, meio-1);
        if(data.posteriorA(lista[meio])) return buscaBinaria(data, meio+1, direita);
        return meio;
    }

    public void listaCompromisso(){
        for(int i = 0; i < this.tam; i++){
            System.out.printf("Compromisso %d: ", i+1);
            Data.mostraData(lista[i]);
        }
    }

}

