package exercicioListaCompromisso;
import exercicioData.*;

public class ListaCompromissoDesordenada {
    private Data[] lista;
    private int tam = 0;

    public ListaCompromissoDesordenada(int capacidade){
        lista = new Data[capacidade];
    }

    public boolean verificaCompromisso(Data data){
        for(int i = 0; i < tam; i++)
            if(data.igualA(lista[i])) return true;
        return false;
    }

    private int verificaCompromissoInt(Data data){
        for(int i = 0; i < tam; i++)
            if(data.igualA(lista[i])) return i;
        return -1;
    }

    public boolean adicionaCompromisso(Data novaData){
        if(verificaCompromissoInt(novaData) != -1 || this.tam > lista.length) return false;
        lista[tam++] = new Data(novaData);
        return true;
    }

    public boolean desmarcaCompromisso(Data novaData){
        int posicao = verificaCompromissoInt(novaData);
        if(posicao == -1) return false;
        lista[posicao].setData(lista[tam-1]);
        tam--;
        return true;
    }

    public void listaCompromisso(){
        for(int i = 0; i < tam; i++){
            System.out.printf("Compromisso %d: ", i+1);
            Data.mostraData(lista[i]);
        }
    }
    
}
