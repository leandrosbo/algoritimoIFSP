// Online C compiler to run C program online
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main() {
    // --- Declaração de Variáveis ---
    int creditos_jogador;
    int integridade_casco;
    int setor_atual;
    int total_setores;

    int evento_aleatorio; // Armazena o número do evento sorteado
    int chance_sucesso;   // Usado para determinar o resultado de ações
    int escolha_jogador;  // Armazena a decisão do jogador (1 ou 2)

    // --- Inicialização do Jogo ---
    // A função 'srand(time(NULL))' usa o tempo atual como "semente" para o gerador
    // de números aleatórios. Isso garante que os eventos sejam diferentes a cada
    // vez que o jogo é executado.
    srand(time(NULL));

    creditos_jogador = 1000;
    integridade_casco = 100;
    setor_atual = 1;
    total_setores = 5;

    // --- Mensagem de Boas-Vindas e Contexto ---

    printf("=========================================\n");
    printf("===      CONTRABANDISTA ESPACIAL      ===\n");
    printf("=========================================\n\n");
    printf("Voce e um piloto tentando a sorte na rota Kessel.\n");
    printf("Sua missao: sobreviver a 5 setores e maximizar seus lucros.\n");
    printf("Voce comeca com %d creditos e sua nave com %d%% de integridade.\n", creditos_jogador, integridade_casco);
    printf("Boa sorte, piloto!\n\n");
    printf("Pressione ENTER para iniciar sua jornada...");
    getchar(); // Espera o jogador pressionar Enter

    // --- Laço Principal do Jogo (while) ---
    // O jogo continua enquanto o jogador não tiver perdido (casco e créditos > 0)
    // e enquanto não tiver chegado ao final da rota (setor_atual <= total_setores).
    while (setor_atual <= total_setores && integridade_casco > 0 && creditos_jogador > 0) {
   
        // Mostra o status atual no início de cada setor
        printf("-----------------------------------------\n");
        printf("Entrando no Setor %d de %d...\n", setor_atual, total_setores);
        printf("Status: [Creditos: %d] - [Casco: %d%%]\n", creditos_jogador, integridade_casco);
        printf("-----------------------------------------\n\n");

        // Sorteia um evento para o setor atual (1, 2 ou 3)
        // A expressão 'rand() % 3' gera um número entre 0 e 2. Somamos 1 para ter o intervalo [1, 3].
        evento_aleatorio = (rand() % 3) + 1;

        // --- Estrutura Condicional para Tratar os Eventos (if / else if / else) ---

        // Evento 1: Carga à Deriva
        if (evento_aleatorio == 1) {
            printf(">> EVENTO: Voce encontrou uma carga de pecas raras a deriva!\n");
            printf(">> Lucro de 250 creditos obtido.\n\n");
            creditos_jogador += 250; // Forma abreviada de: creditos_jogador = creditos_jogador + 250
        }
        // Evento 2: Ataque de Piratas
        else if (evento_aleatorio == 2) {
            printf(">> EVENTO: Piratas Espaciais surgem e exigem 300 creditos!\n");
            printf("   1 - Lutar contra os piratas.\n");
            printf("   2 - Pagar 300 creditos para evitar o conflito.\n");
            printf("Qual a sua decisao? ");
            scanf("%d", &escolha_jogador);
          

            if (escolha_jogador == 1) { // Escolheu lutar
                printf("\n>> Voce decide lutar! Os canhoes sao acionados...\n");
                chance_sucesso = (rand() % 10) + 1; // Sorteia um número de 1 a 10

                if (chance_sucesso > 5) { // 50% de chance de ganhar (6, 7, 8, 9, 10)
                    printf(">> VITORIA! Voce derrotou os piratas e saqueou 150 creditos dos destrocos!\n\n");
                    creditos_jogador += 150;
                } else {
                    printf(">> DERROTA! Sua nave foi atingida! O casco perdeu 40 de integridade!\n\n");
                    integridade_casco -= 40; // Forma abreviada
                }
            } else { // Escolheu pagar
                printf("\n>> Voce paga os piratas e eles partem em paz.\n\n");
                creditos_jogador -= 300;
            }
        }
        // Evento 3: Inspeção da Patrulha
        else {
            printf(">> EVENTO: A Patrulha Galactica ordena que voce pare para uma inspecao!\n");
            printf("   1 - Tentar persuadir o guarda a te liberar.\n");
            printf("   2 - Oferecer um 'incentivo' de 150 creditos (suborno).\n");
            printf("Qual a sua decisao? ");
            scanf("%d", &escolha_jogador);
           

            if (escolha_jogador == 1) { // Tentar persuadir
                printf("\n>> Voce tenta usar sua labia com o guarda...\n");
                chance_sucesso = (rand() % 10) + 1;

                if (chance_sucesso > 6) { // 40% de chance de sucesso (7, 8, 9, 10)
                    printf(">> SUCESSO! O guarda acredita na sua historia e te libera!\n\n");
                } else {
                    printf(">> FALHA! O guarda nao gostou da sua atitude e aplicou uma multa de 400 creditos!\n\n");
                    creditos_jogador -= 400;
                }
            } else { // Escolheu subornar
                printf("\n>> Voce discretamente passa os creditos para o guarda, que sorri e te deseja 'boa viagem'.\n\n");
                creditos_jogador -= 150;
            }
        }

        // Pausa para o jogador ler o que aconteceu
        printf("Pressione ENTER para continuar para o proximo setor...");
        getchar();

        // Avança para o próximo setor
        setor_atual++;
    }

    // --- Fim do Jogo: Verificação de Vitória ou Derrota ---
    printf("\n\n=========================================\n");
    printf("===          FIM DA JORNADA         ===\n");
    printf("=========================================\n\n");

    if (integridade_casco <= 0) {
        printf("DERROTA: Sua nave foi destruida no espaco profundo.\n");
        printf("Fim de jogo.\n");
    } else if (creditos_jogador <= 0) {
        printf("DERROTA: Voce esta sem creditos e nao pode continuar.\n");
        printf("Fim de jogo.\n");
    } else {
        printf("VITORIA! Voce completou a rota com sucesso!\n");
        printf("Pontuacao Final (Creditos): %d\n", creditos_jogador);
        printf("Integridade do Casco Restante: %d%%\n", integridade_casco);
    }

    printf("\n\n");

    return 0; // Indica que o programa terminou com sucesso
}