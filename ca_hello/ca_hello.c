#include <stdio.h>
#include <stdlib.h>
#include <tee_client_api.h>

/* Define el mismo UUID que en la TA */
static const TEEC_UUID ta_hello_uuid = {
    0xe7b8c9d0, 0x1234, 0x5678,
    { 0x9a, 0xbc, 0xde, 0xf0, 0x12, 0x34, 0x56, 0x78 }
};

int main(void)
{
    TEEC_Result res;
    TEEC_Context ctx;
    TEEC_Session sess;
    uint32_t err_origin;

    /* Inicializa el contexto */
    res = TEEC_InitializeContext(NULL, &ctx);
    if (res != TEEC_SUCCESS) {
        printf("Error TEEC_InitializeContext: 0x%x\n", res);
        return 1;
    }

    /* Abre una sesión con la TA */
    res = TEEC_OpenSession(&ctx, &sess, &ta_hello_uuid,
                           TEEC_LOGIN_PUBLIC, NULL, NULL, &err_origin);
    if (res != TEEC_SUCCESS) {
        printf("Error TEEC_OpenSession: 0x%x, origin: 0x%x\n", res, err_origin);
        TEEC_FinalizeContext(&ctx);
        return 1;
    }

    /* Invoca el comando de la TA */
    res = TEEC_InvokeCommand(&sess, 0, NULL, &err_origin);
    if (res != TEEC_SUCCESS) {
        printf("Error TEEC_InvokeCommand: 0x%x, origin: 0x%x\n", res, err_origin);
    } else {
        printf("CA: Hola mundo desde la CA\n");
    }

    /* Cierra la sesión y finaliza el contexto */
    TEEC_CloseSession(&sess);
    TEEC_FinalizeContext(&ctx);

    return 0;
}