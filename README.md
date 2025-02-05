# Atividade EmbarcaTech - Temporizador periódico (Semáforo)

## Visão Geral da Atividade
Esta atividade tem como objetivo desenvolver um sistema de controle de semáforo utilizando a placa **BitDogLab** e o microcontrolador **RP2040 (Raspberry Pi Pico W)**, além de uma simulação do projeto no Wokwi. O sistema opera da seguinte forma:

1. **O semáforo inicia na cor vermelha**.
2. **A cada 3 segundos (3.000ms), o LED muda de estado** na seguinte ordem:
   - Vermelho → Amarelo
   - Amarelo → Verde
   - Verde → Vermelho (reiniciando o ciclo)
3. **A gestão da temporização é feita com a função `add_repeating_timer_ms()`** do **Pico SDK**.
4. **A rotina principal imprime mensagens a cada segundo (1.000ms) pela porta serial**.

## Observação Importante
Como as GPIOs da placa BitDogLab estão distribuídas de forma diferente da distribuição recomendada na Tarefa para a simulação no Wokwi (Além de não existir um único led com cor amarela para o semáforo), foi criada uma outra branch com o nome 'BitDogLab' com o código adaptado para a placa. (Ambos códigos funcionam na BitDogLab, apenas com LEDs acendendo de forma diferente)

## Requisitos de Software
Para compilar e executar o programa, serão necessários:
- **Pico SDK** instalado
- **Compilador ARM (arm-none-eabi-gcc)**
- **Ambiente de desenvolvimento** (Ex: VS Code)
- **Extensão do Wokwi**
- **Extensão do Raspberry Pi**

## Instruções de Compilação e Execução
1. **Clonar o projeto para sua máquina:**
   ```sh
   git clone https://github.com/apribeiro-cic/periodic_timer
   ```
   
2. **Importar o projeto pela extensão Raspberry Pi:**
   
   Esse passo pode não ser necessário, pois ao estar com a extensão instalada o VSCode cria a pasta build automaticamente ao ser executado. Porém, se esse não for o caso será necessário importar o projeto pela extensão Raspberry Pi:

   Clique na barra lateral em **Raspberry Pi Pico Project** e em **Import Project**
   
   ![image](https://github.com/user-attachments/assets/8f9351c3-8030-4e3c-a6a5-49b07a4b3265)

   Selecione o diretório e clique em **Import**
   
   ![image](https://github.com/user-attachments/assets/f4ed807c-1d56-427f-a787-fa82fa97228d)

  
4. **Compile o projeto e abra o arquivo 'diagram.json':**
   Compile o projeto e abra o arquivo 'diagram.json' para que a simulação do projeto apareça (Extensão do Wokwi deve estar instalada)
   
   ![image](https://github.com/user-attachments/assets/bae6bf4e-25d0-4d88-94ee-4f04f3698c9c)


5. **Inicie a simulação do projeto:**
   
   ![image](https://github.com/user-attachments/assets/7a22a7f9-34b2-4efb-b09a-a487b007b51c)


## Uso do Programa
1. **Ao iniciar o sistema, o LED vermelho acenderá**.
2. **A cada 3 segundos, a cor do LED mudará seguindo a sequência do semáforo**: Vermelho → Amarelo → Verde → Vermelho.
3. **A cada segundo, uma mensagem será impressa no terminal, indicando que o timer está rodando**.

## Considerações Finais
Este projeto demonstra o uso de **temporização periódica utilizando a função `add_repeating_timer_ms()`**, junto com o controle de LEDs no RP2040. A implementação foi testada na BitDogLab e simulada no Wokwi.

