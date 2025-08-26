#include <stdbool.h>
#include <stdio.h>

#define MAX_NO_OF_LINES 50
#define MAX_LENGTH 50
#define MAX_SYMBOLS 50

// Function declarations
int reg_code(char *reg);
int reg_code_2(char *reg);
int instruction_size(char mnemonic[10]);
void opcode(char input_line[MAX_LENGTH]);
char *fgets_c(char *buffer, int limit, FILE *stream);
void opcode_RST(char mnemonic[10], unsigned int addr);
void opcode_fixed(char mnemonic[10], unsigned int addr);
void opcode_MVI(char reg_dest[10], char data[10], unsigned int addr);
void opcode_acc_instr(char *mnemonic, char *data, unsigned int addr);
void opcode_IN_OUT(char mnemonic[10], char port[10], unsigned int addr);
void opcode_MOV(char reg_dest[10], char reg_src[10], unsigned int addr);
void opcode_instruction_rp(char mnemonic[10], char regis[10], unsigned int addr);
void opcode_instruction_array1(char mnemonic[10], char regis[10], char data[10], unsigned int addr);
void opcode_instruction_cond(char mnemonic[10], char cond[10], unsigned int addr,char* target_label);

//CUSTOM STRING FUNCTIONS
char *strcpy_c(char *dest, const char *src);
void strcspn_nl(char input_cur[MAX_LENGTH]);
char *strchr_c(const char *str, int character);
int strcmp_c(char input_cur[MAX_LENGTH], const char *text);
int strlen_c(char input_cur[MAX_LENGTH]);

//INSTRUCTIONS CHECKING FUNCTIONS
bool is_fixed_instruction(char *mnemonic);
bool check_if_present_ia1(char *mnemonic);
bool check_if_present_ia2(char *mnemonic);
bool check_if_present_acc(char *mnemonic);
bool check_transfer_instructions(char *mnemonic);


// Order of the registers in 8085 microprocessor
char *regs[] = {"B","C","D","E","H","L","M","A"};
char *regs_2[] = {"B","D","H","SP"};

// Array of instructions
char *instruction_array1[] = {"ADD","ADC","SUB","SBB","ANA","XRA","ORA","CMP","INR","DCR"};
char *instruction_array2[] = {"LXI","INX","DCX","DAD","LDAX","STAX","PUSH","POP"};
char *transfer_instructions[] = {"JMP","CALL","RET"};

// Symbol table
struct sym {
    char label[10]; //For storing the label
    unsigned int addr; //Respective address
};

//Create an array of structures to store further symbols
struct sym symbol_table[MAX_SYMBOLS];

//To track the symbol count
int sym_count=0;

//To keep track of the address (Program Counter)
unsigned int program_counter=0x0000;

//Base Address
unsigned int base_address = 0x2000;

// To find the size of the instructions
int instruction_size(char mnemonic[10]){

    //2-Byte Instructions
    if(strcmp_c(mnemonic,"MVI") || strcmp_c(mnemonic,"ADI") || strcmp_c(mnemonic,"ACI") || strcmp_c(mnemonic,"SUI")
        || strcmp_c(mnemonic,"SBI") || strcmp_c(mnemonic,"ANI")|| strcmp_c(mnemonic,"XRI")
        || strcmp_c(mnemonic,"ORI") || strcmp_c(mnemonic,"CPI") || strcmp_c(mnemonic,"IN") || strcmp_c(mnemonic,"OUT"))
        return 2;

    //3-Byte Instructions
    if(strcmp_c(mnemonic,"LXI") || strcmp_c(mnemonic,"JMP") || strcmp_c(mnemonic,"CALL")) return 3;

    //1-Byte Instructions
    return 1;
}

// To find the reg_code of the register (for single registers)
int reg_code(char *reg) {
    for(int i=0;i<8;i++) if (strcmp_c(reg,regs[i])==1) return i;
    return -1;
}

// To find the reg_code of the register pair (B-C, D-E, H-L, SP)
int reg_code_2(char *reg) {
    for(int i=0;i<4;i++) if (strcmp_c(reg,regs_2[i])==1) return i;
    return -1;
}

//STRING FUNCTIONS
// Remove newline character
void strcspn_nl(char input_cur[MAX_LENGTH]) {
    for(int i=0; input_cur[i]!='\0'; i++) {
        if(input_cur[i]=='\n') { input_cur[i]='\0'; break; }
    }
}

// String length
int strlen_c(char input_cur[MAX_LENGTH]) {
    int length = 0;
    for (int i=0; input_cur[i]!='\0'; i++) length++;
    return length;
}

// Custom strcmp function returning 1 if equal
int strcmp_c(char input_cur[MAX_LENGTH],const char *text) {
    int i = 0;
    while(input_cur[i]!='\0' && text[i]!='\0') {
        if(input_cur[i] != text[i]) return 0;
        i++;
    }
    return (input_cur[i]=='\0' && text[i]=='\0') ? 1 : 0;
}

// To check if the given instruction is present in the instruction_array1
bool check_if_present_ia1(char *mnemonic) {
    for(int i=0;i<10;i++) {
        if(strcmp_c(mnemonic,instruction_array1[i])==1)
            return true;
    }
    return false;
}

// To check if the given instruction is present in the instruction_array2
bool check_if_present_ia2(char *mnemonic) {
    for(int i=0;i<10;i++) {
        if(strcmp_c(mnemonic,instruction_array2[i])==1)
            return true;
    }
    return false;
}

// To check if the given instruction is present in the transfer instructions
bool check_transfer_instructions(char *mnemonic) {
    for(int i=0;i<3;i++) {
        if(strcmp_c(mnemonic,transfer_instructions[i])==1)
            return true;
    }
    return false;
}

// To check if the given instruction is present in the accumulator instructions
bool check_if_present_acc(char *mnemonic) {
    //Create a structure for storing accumulator instructions with their opcode
    struct acc_instr {
        char *mnemonic;
        int opcode;
    };
    struct acc_instr acc_table[] = {
        {"ADI",0xC6},{"ACI",0xCE},{"SUI",0xD6},{"SBI",0xDE},
        {"ANI",0xE6},{"XRI",0xEE},{"ORI",0xF6},{"CPI",0xFE}
    };
    for(int iter = 0 ; iter < 8; iter++){
        if(strcmp_c(mnemonic,acc_table[iter].mnemonic)==1) {
            return true;
        }
    }
    return false;
}


// Fixed instructions table
struct fixed_instr {
    char *mnemonic;
    int opcode;
};

struct fixed_instr fixed_table[] = {
    {"NOP",0x00},{"HLT",0x76},{"EI",0xFB},{"DI",0xF3},
    {"RLC",0x07},{"RRC",0x0F},{"RAL",0x17},{"RAR",0x1F},
    {"CMA",0x2F},{"CMC",0x3F},{"STC",0x37},{"DAA",0x27},
    {"RIM",0x20},{"SIM",0x30}
};

// Function to check if mnemonic exists in fixed_table
// Returns true if found and increments pc, false otherwise
bool is_fixed_instruction(char *mnemonic) {
    int count = sizeof(fixed_table)/sizeof(fixed_table[0]);
    for(int i = 0; i < count; i++) {
        if(strcmp_c(mnemonic, fixed_table[i].mnemonic) == 1) {
            program_counter += 1;  // Increment PC for 1-byte instruction
            return true;  // Found in fixed_table
        }
    }
    return false;  // Not found
}

//Own fgets function
char *fgets_c(char *buffer, int limit, FILE *stream) {
    int index = 0;
    int character;

    if (limit <= 0 || buffer == NULL || stream == NULL) {
        return NULL;
    }

    while (index < limit - 1) {
        if (scanf("%c",&character) != 1) {
            //Indicates the stream is empty
            if (index == 0) {
                return NULL;
            }
            break;
        }
        buffer[index++] = character;

        //If New line is encountered break
        if (character == '\n') {
            break;
        }
    }
    buffer[index] = '\0';
    return buffer;
}

// Customised strcpy function
char *strcpy_c(char *dest, const char *src) {
    char *temp = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return temp;
}

// Customised strchr function
char *strchr_c(const char *str, int character) {
    while (*str != '\0') {
        if (*str == (char)character) {
            return (char *)str;   // return pointer to first match
        }
        str++;
    }
    return NULL;  // not found
}

// MOV Opcode Function
void opcode_MOV(char reg_dest[10], char reg_src[10], unsigned int addr) {
    int dest = reg_code(reg_dest);
    int source = reg_code(reg_src);
    if (dest == -1 || source == -1) { printf("0x%04X Invalid Register\n", addr); return; }
    printf("0x%04X %02X\n", addr, 0x40 + dest*8 + source);
}

// Arithmetic/Logical Opcode Function
void opcode_instruction_array1(char mnemonic[10], char regis[10], char data[10], unsigned int addr) {
    int opcode_val=-1;
    int regc = reg_code(regis);
    if(regc == -1) { printf("0x%04X Invalid Register\n", addr); return; }

    if(strcmp_c(mnemonic, "ADD") == 1) opcode_val = 0x80 + regc;
    else if(strcmp_c(mnemonic, "ADC") == 1) opcode_val = 0x88 + regc;
    else if(strcmp_c(mnemonic, "SUB") == 1) opcode_val = 0x90 + regc;
    else if(strcmp_c(mnemonic, "SBB") == 1) opcode_val = 0x98 + regc;
    else if(strcmp_c(mnemonic, "ANA") == 1) opcode_val = 0xA0 + regc;
    else if(strcmp_c(mnemonic, "XRA") == 1) opcode_val = 0xA8 + regc;
    else if(strcmp_c(mnemonic, "ORA") == 1) opcode_val = 0xB0 + regc;
    else if(strcmp_c(mnemonic, "CMP") == 1) opcode_val = 0xB8 + regc;
    else if(strcmp_c(mnemonic, "INR") == 1) opcode_val = 0x04 + regc*8;
    else if(strcmp_c(mnemonic, "DCR") == 1) opcode_val = 0x05 + regc*8;

    printf("0x%04X %02X\n", addr, opcode_val);
}

// Register pair instructions opcode generation function
void opcode_instruction_rp(char mnemonic[10], char regis[10], unsigned int addr) {
    int opcode_val = -1;
    int regc = reg_code_2(regis);
    if(regc == -1) { printf("0x%04X Invalid register\n", addr); return; }

    if(strcmp_c(mnemonic, "LXI") == 1)  opcode_val=0x01 + regc*0x10;
    else if(strcmp_c(mnemonic, "INX") == 1) opcode_val=0x03 + regc*0x10;
    else if(strcmp_c(mnemonic, "DCX") == 1) opcode_val=0x0B + regc*0x10;
    else if(strcmp_c(mnemonic, "DAD") == 1) opcode_val=0x09 + regc*0x10;
    else if(strcmp_c(mnemonic, "PUSH") == 1) opcode_val=(regc==3)?0xF5:0xC5 + regc*0x10;
    else if(strcmp_c(mnemonic, "POP") == 1) opcode_val=(regc==3)?0xF1:0xC1 + regc*0x10;
    else if(strcmp_c(mnemonic, "LDAX") == 1) opcode_val=(regc==0)?0x0A:0x1A;
    else if(strcmp_c(mnemonic, "STAX") == 1) opcode_val=(regc==0)?0x02:0x12;

    if(opcode_val != -1) printf("0x%04X %02X\n", addr, opcode_val);
    else printf("0x%04X Invalid instruction for register pair\n", addr);
}

// JMP--CALL--RET
void opcode_instruction_cond(char mnemonic[10], char cond[10], unsigned int addr, char* target_label){
    int opcode_val=-1;
    char *cond_codes[]={"NZ","Z","NC","C","PO","PE","PM","M"};
    int cond_index=-1;
    for(int i=0;i<8;i++) {
        if(strcmp_c(cond,cond_codes[i])==1) {
            cond_index=i;
            break;
        }
    }

    //Label Handling
    unsigned int target_addr=0;
    bool found=false;
    for(int iter = 0; iter < sym_count; iter++) {
        if(strcmp_c(target_label,symbol_table[iter].label)==1) {
            target_addr=symbol_table[iter].addr;
            found=true;
            break;
        }
    }
    //If Label is not found then it should be the address
    if(!found) {
        sscanf(target_label,"%x",&target_addr);
    }

    if(strcmp_c(mnemonic,"JMP")==1) opcode_val=(cond_index==-1) ? 0xC3 : 0xC2 + cond_index*0x08;
    else if(strcmp_c(mnemonic,"CALL")==1) opcode_val=(cond_index==-1) ? 0xCD : 0xC4 + cond_index*0x08;
    else if(strcmp_c(mnemonic,"RET")==1) opcode_val=(cond_index==-1) ? 0xC9 : 0xC0 + cond_index*0x08;

    if(opcode_val!=-1){
        if(strcmp_c(mnemonic,"RET")==1) printf("0x%04X %02X\n", addr, opcode_val);
        else {
            unsigned char low=target_addr & 0xFF, high=(target_addr>>8)&0xFF;
            printf("0x%04X %02X %02X %02X\n", addr, opcode_val, low, high);
        }
    } else printf("0x%04X Invalid conditional instruction\n", addr);
}


// Accumulator + Immediate data instruction set
void opcode_acc_instr(char *mnemonic, char *data, unsigned int addr) {
    unsigned int value;
    if(sscanf(data,"%x",&value)!=1) {
        printf("0x%04X Invalid data for %s\n", addr, mnemonic);
        return;
    }

    struct acc_instr { char *mnemonic; int opcode; };
    struct acc_instr acc_table[] = { {"ADI",0xC6},{"ACI",0xCE},{"SUI",0xD6},{"SBI",0xDE},
        {"ANI",0xE6},{"XRI",0xEE},{"ORI",0xF6},{"CPI",0xFE} };

    int found = 0;
    for(int i=0;i<8;i++) {
        if(strcmp_c(mnemonic,acc_table[i].mnemonic)==1) {
            printf("0x%04X %02X %02X\n", addr, acc_table[i].opcode, value & 0xFF);
            found = 1;
            break;
        }
    }
    if(!found) printf("0x%04X Invalid accumulator instruction: %s\n", addr, mnemonic);
}

// RST n
void opcode_RST(char mnemonic[10], unsigned int addr) {
    int number;
    if(sscanf(mnemonic,"%d",&number)!=1 || number<0 || number>7) {
        printf("0x%04X Invalid RST\n", addr); return;
    }
    printf("0x%04X %02X\n", addr, 0xC7 + number * 8);
}

// IN/OUT port
void opcode_IN_OUT(char mnemonic[10], char port[10], unsigned int addr) {
    unsigned int p;
    sscanf(port,"%x",&p);
    if(strcmp_c(mnemonic,"IN")==1) printf("0x%04X %02X %02X\n", addr, 0xDB, p&0xFF);
    else if(strcmp_c(mnemonic,"OUT")==1) printf("0x%04X %02X %02X\n", addr, 0xD3, p&0xFF);
}
void opcode_fixed(char mnemonic[10], unsigned int addr) {
    int found = 0;
    int count = sizeof(fixed_table)/sizeof(fixed_table[0]);
    for(int i=0;i<count;i++){
        if(strcmp_c(mnemonic, fixed_table[i].mnemonic)==1){
            printf("0x%04X %02X\n", addr, fixed_table[i].opcode);
            found = 1;
            break;
        }
    }
    if(!found) printf("0x%04X Invalid instruction\n", addr);
}

void opcode_MVI(char reg_dest[10], char data[10], unsigned int addr) {
    int dest = reg_code(reg_dest);
    unsigned int value;
    if(dest == -1) {
        printf("0x%04X Invalid Register\n", addr);
        return;
    }
    if(sscanf(data,"%x",&value) != 1) {
        printf("0x%04X Invalid Data\n", addr);
        return;
    }
    unsigned int opcode_val = (reg_dest[0]=='A')?0x3E : 0x06 + dest*8; // simplified formula
    printf("0x%04X %02X %02X\n", addr, opcode_val, value & 0xFF);
}

// Main opcode generator function
void opcode(char input_line[MAX_LENGTH]) {
    char mnemonic[10], operand1[10], operand2[10];
    int n = sscanf(input_line,"%s %[^,],%s", mnemonic, operand1, operand2);

    //Update the current address based on the instruction size
    unsigned int curr_addr = base_address + program_counter;

    //MOV
    if (strcmp_c(mnemonic,"MOV") == 1 && n == 3) opcode_MOV(operand1, operand2, curr_addr);

    //JMP/CALL/RST
    else if(check_transfer_instructions(mnemonic)){
        char cond[10]="", target_label[10]="";

        //If JMP
        if(n==3) {
            sscanf(operand1,"%s",cond);
            strcpy_c(target_label,operand2);
        }
        else if(n==2) {
            strcpy_c(target_label,operand1);
        }
        opcode_instruction_cond(mnemonic,cond,curr_addr,target_label);
    }

    // Arithmetic/Logical Opcode Function
    else if (check_if_present_ia1(mnemonic)) opcode_instruction_array1(mnemonic, operand1, operand2, curr_addr);

    // Register pair instructions opcode generation function
    else if (check_if_present_ia2(mnemonic)) opcode_instruction_rp(mnemonic, operand1, curr_addr);

    //MVI
    else if (strcmp_c(mnemonic,"MVI") == 1 && n == 3) opcode_MVI(operand1, operand2, curr_addr);

    //Accu Instrc
    else if (check_if_present_acc(mnemonic)) opcode_acc_instr(mnemonic, operand1, curr_addr);

    //RST
    else if(strcmp_c(mnemonic,"RST")==1) opcode_RST(operand1, curr_addr);

    //IN/OUT
    else if(strcmp_c(mnemonic,"IN")==1 || strcmp_c(mnemonic,"OUT")==1) {
        opcode_IN_OUT(mnemonic, operand1, curr_addr);
    }

    //Other Standalone Fixed Instructions
    else if (is_fixed_instruction(mnemonic)) opcode_fixed(mnemonic,curr_addr);

    program_counter += instruction_size(mnemonic);
}

int main() {
    char input_lines[MAX_NO_OF_LINES][MAX_LENGTH];
    int total_lines = 0;

    printf("Enter up to 50 Instructions with HLT at end:\n");

    for (int line_iter = 0; line_iter < MAX_NO_OF_LINES; line_iter++) {
        //Get the instruction input line by line
        if (!fgets_c(input_lines[line_iter], MAX_LENGTH, stdin)) {
            break;
        }
        //Remove the newline
        strcspn_nl(input_lines[line_iter]);

        //Label Handling
        char temp_line[MAX_LENGTH];
        strcpy_c(temp_line,input_lines[total_lines]);
        char *label_pos=strchr_c(temp_line,':');
        if(label_pos){
            //Add the null terminator
            *label_pos='\0';
            //copy to label in symbol table arrray
            strcpy_c(symbol_table[sym_count].label,temp_line);
            //Store curre
            symbol_table[sym_count].addr= program_counter + base_address;
            sym_count++;

            //update the remainig instruction to input
            strcpy_c(input_lines[total_lines],label_pos+1);
        }

        if (strlen_c(input_lines[line_iter]) == 0) break;
        if (strcmp_c(input_lines[line_iter], "HLT") == 1) {
            total_lines++;
            break;
        }
        total_lines++;
    }

    printf("--Addr OP LD UD--\n");
    for (int line_iter = 0; line_iter < total_lines; line_iter++) {
        opcode(input_lines[line_iter]);
    }
    return 0;
}
