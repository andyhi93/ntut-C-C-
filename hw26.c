#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define GATEVALUE(Gate) int(*GateValue)(struct _Gate*)
typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
}Gate;
int GateORValue(Gate *gate) {return gate->input1 || gate->input2;}
int GateANDValue(Gate *gate) {return gate->input1 && gate->input2;}
int GateNOTValue(Gate *gate) {return gate->input1?0:1;}
int GateBUFFERValue(Gate *gate) {return gate->input1;}
void CreateGate(Gate *obj, char type, int input1, int input2) {
    obj->input1 = input1;
    obj->input2 = input2;
    switch (type)
    {
    case 'A':
        obj->GateValue = GateANDValue;
        break;
    case 'O':
        obj->GateValue = GateORValue;
        break;
    case 'N':
        obj->GateValue = GateNOTValue;
        break;
    case 'B':
        obj->GateValue = GateBUFFERValue;
        break;
    default:
        printf("Error type\n");
        break;
    }
}
int main() {
    Gate gate[3];
    int x[3];
    char g[3];
    scanf("%d %d %d",&x[0],&x[1],&x[2]);
    scanf(" %c %c %c", &g[0], &g[1], &g[2]);
    //printf("%d %d %d %c %c %c\n", x[0], x[1], x[2], g[0], g[1], g[2]);
    CreateGate(&gate[0],g[0],x[0],x[0]);
    int P_output = gate[0].GateValue(&gate[0]);
    CreateGate(&gate[1],g[1],x[1],P_output);
    int Q_output = gate[1].GateValue(&gate[1]);
    CreateGate(&gate[2],g[2],x[2],Q_output);
    int R_output = gate[2].GateValue(&gate[2]);
    printf("%d %d %d\n", P_output, Q_output, R_output);
}