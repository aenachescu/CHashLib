#include "sha0.h"
#include <stdio.h>
#include <string.h>

#include "linux_color.h"
#include "util.h"

static const char* expectedHash[] = {
    "f96cea198ad1dd5617ac084a3d92c6107708c0ef",
    "37f297772fae4cb1ba39b6cf9cf0381180bd62f2",
    "5173ec2335c575dee032b01562a41330eb803503",
    "5dfc8a87381aa03e963ab26a645f0fdd60847dfa",
    "a6a04d2cec0bcf73cee87ec8be03c805aa81a825",
    "3bdeb2aa3ced005f6244df1e73bbb2c1ef222d9f",
    "21aeb6df1fd0bdf6d74e6462bc2fdee69a7b2688",
    "07f905605a7e7d5536f60c37a5a8778c4120c0cd",
    "936e9a21d1c70c90ad317177c23f315ddc770792",
    "deba15af726da55e1d72c87a44cd5238cf47209c",
    "33652f120dafab03003df7ec9624485ecf916176",
    "8b7ce6884ca52faad04c28adfd4b95801f872731",
    "71b9fb04a15023122d31437b36ed819d4fab5609",
    "a715c8a4bdda9b07d463975f5ec56c83c81cef48",
    "d183ca819970df1b189d8b14c62e39a7f1dadd02",
    "f772d44225f97fc03b1ed5fcb82ab8fdcc32bbe9",
    "087e30df2db88a6fe61b0be558c9aaf206214f19",
    "353da09a87704dd6c09c4fb5cde0b562d16acdc2",
    "4a27fe968f4fee4bb76a6ad6dd7e8e4e3efeb099",
    "ba0b3f51fce4601fd7e42b137a175562902baab8",
    "0462f5ae57156f17a1ace5fa99c4a92e71f2fea1",
    "740494a650d520084a862476e37b940199c8a8fe",
    "6123d7c3664a42272338067e5970119b6e8afe5e",
    "308fe4efed344740dee49590b6b2d723c88e204a",
    "3f76f3b698f58f99f748bd539acb7e30b394ed37",
    "03c45eab6c8a8d21e2cb47b8202d990036a3b1f5",
    "d437e0cd23ade5a01c739b221f9db1074338e2d0",
    "d26cd821178b99efc109db57ee03a0c5c94f1621",
    "ac36fd17e95b505b5c77f7ed191e036f9a9cb697",
    "64bac0435580bc176235e2041e5999a7af42bba2",
    "ea0850525fb9a5dae72c4c8a706c566d7fc849da",
    "3251a31ed72b5cd4519a6586938b38483d39ec84",
    "461f29625d85ab15700ffc85c469a9473812a6e6",
    "2b4cf59ed002eeae7fb65c1b132f2ccb5d09ea53",
    "7185fa94bc982527c278323bb716b2fef4e6e2fd",
    "bec9e3cd18ba96de801f9002b06099089bcfe384",
    "f5b019db3f34d09e8aeb1da3957392fd0a5af7ab",
    "9b0fc6b3f5fd33c61aa09fb5613993e84138a8de",
    "1bdc5870df43f63126d81b29cbdd663a0bc3193c",
    "d73cb48786215687363ccdcd7c2690b01bee08d5",
    "ff09149b35fa92dc1b0706a6c363b86ecc13499a",
    "9dd4357cdc4632592ecf8364a877b4e492a71293",
    "28a86ac7917ab6b7e51a67ffe767fec914de7a9e",
    "7102336f2e809340760b59d5374cbbe555c5cf70",
    "a9719aeb1716be22211976f1c5df375351fd298c",
    "03dce2c6f3a08288de3a35561eb5a3ae1ff88cb8",
    "adce1143b087a9b743d8b6a0e05c57fbebf76e76",
    "71bf1ed222006b5a42a6411b589ea8ee44ffd649",
    "935810e29020b300a1ad546da4b41ea421dc20cd",
    "2333b2ff2bcd2bc2963e0038eab9a47ad965cb92",
    "fc422d42c386032f8abb26816ad072beb0cff5f8",
    "d911297abd34f6e8148527b3ddcb38f5c46e42e0",
    "44f926bd761e71a2d93c9aeecccaa1215f6b3ee5",
    "71b1ee28a448b9176d45ce5102747c32758967a1",
    "38351a9ea6bcedb9bf4b48067f0bcdb5c4efcda8",
    "0ff59f7cb9afc10d7abcdc9ab8c00e0e7b02034f",
    "f826f1db56ddb270e25f21a7a40c4163b51c47ff",
    "16da02dff9e96b8f00604050b1be0011fafdf492",
    "f6e9021b3175e5be708b41aa78e37ab10589dc8b",
    "2757eac232d7c0d3e4d63c1a7941acad9a796f79",
    "f371323d7469f132ab60fc654dd0e0ab088296f5",
    "bdcf03ee0b12386fb747689ec22a7cc91f857393",
    "d97afbabbba736eed030f7849a8ebbb799114ede",
    "61191abbfdb5d1c77bceae556de82b39bfbfcb9a",
    "6381391134b901db7a5a03699339bca31c409dde",
    "b15055fc266b84dbb9f453a96d136bf3376cddeb",
    "e7d9bd6d0d17e088fc7bdd427a4f3fe358da972e",
    "75b9e5235e2e98be443b333399aa1c70c5ef3a77",
    "7cb33b17cc586f6d5d696ff2704f19fc5c9171a9",
    "a4295df696eb44191994144de1b7412f010e7e99",
    "42d825c47b13fad1cfa39c507fbd4734d8e34c26",
    "02ec96355dfbf744bc9416e1ae792654ae6ddc8c",
    "0fce744d504d8f117593cc0d84af87c2610542df",
    "861fd92397da1e4c625be8f594bb9ceaf8bb7478",
    "632444335bf551c7e9fdf979e79b4f5da45146ce",
    "75c78c56eafd6e6ffffddbe471ea1900b2c3873f",
    "3eafdb3b58be01abf266b2762a6b8f2de66b957e",
    "62a090724de48912c7b0f4fd4c5d03ee03f94bd7",
    "bb9866e8d0f190400e6eea153010e011071d0e03",
    "0b4ab423492e9ed65ac4de2663d6927edde57338",
    "b452c850f2e6e58d46e4c9b6880bdf19f9532ed3",
    "7eff1f16d35c972966813e8357f9c24f6825766e",
    "51d8e53a96404907035a5d6bf61a77418199cfa9",
    "9cd125778cdcf0f8adbdddd068553980fb57311e",
    "35f110b0942f8653892c964025fabad99c89dba0",
    "bfcd7e57f8c9fd6473a35c15a27528b32390b492",
    "bd5a41bc451724e5de472168ff182ef1bd5e94d4",
    "729b0733d5af4ab4ac2a9ff7bbedf02288620b94",
    "2b888f9eb8b8b4c6aef1938c346a91d94a95f4fb",
    "05a3a6e296aec9fc2e113653320535d369a34b9e",
    "f53996440f3768f33c2a64bfa445161d7a1cc985",
    "d821e01d83f5044f2b0cd4f30cc5b4f74d6879ee",
    "8daeb740dca2ee085ad3f9c01e8fbcecd2ad9b99",
    "e2545c1babbaec37d635ebee8ac3e60cfb11bbaf",
    "766e5b00c2e90308861f8d09def0774bf15dafee",
    "a88ce0ff9b318e272610cf5bb36cb285bc27bed5",
    "3d441ad383bc8f0fdcc569f3da303b873a273a89",
    "fc322f7cd3091df3439a9c3fc94842e32c493cb0",
    "b5baaa5690bdb6aa4c83aa1560d9d6d763bf846c",
    "e2824ba068e77ec6ad0567a18d1aae4fd4898574",
    "36875316f4a0658b1f37cda3e4ca663c377bfcda",
    "b28ed37d8755689f459506ee3bbc6674a5e26b48",
    "1353aafd998887b5dbdabfac513398531f7c0c99",
    "9386581062928ed9a2a0f57e443c659c03c44f91",
    "7f2475657bd2bf94bef7563a8311e3725d07f6cd",
    "8f1ed3353ee58f08fb7877f91c51df9015fd6338",
    "709fdca1047adc48b4804c9a24dac0f68b43a8df",
    "08a2baa6d0178f8fd6acea088c08476fd15b8f83",
    "4530c951ccb7dd2712a0b539a61b4794d6cb1d20",
    "e0594111f766321ce3da60943ce97d105155931e",
    "568c7bbe786d6ed85078c0b041fa7a076ce878eb",
    "d6d840de7cecaa474055c9334d7d5ff85810f325",
    "7c74c4f24f4e2df4c351f60635b7ccd7302a8799",
    "7778e1ad1379af8a93cbc8c3273df10501427307",
    "e70bce6f509e02ab73c629abda4dbaa791759123",
    "7874288de606f592cc407915e61fce92e12de5e1",
    "81ee2ec00663636c1703085a6054bcc09365a895",
    "70a69e5b6c5466afcc48714f1f3bbb98e4f5e2e0",
    "ce5aa236279e7f9766182e9557e12d2fd9c1e379",
    "86683a324cedc63bef20d6425cb1680e4054cf57",
    "451fa4e832121c06da75b5a4d4bcf705a1deec9c",
    "ccb60ddead2e1cdd84094b6c3215d2845697ad02",
    "e43e1629533a1bfd6b0f9f59f313a32983bcc852",
    "324181b9ccdaaf546600b13a74a1dad379462fc4",
    "6ec6d30ab25f86fdf5ec9d0778f7bc6d28b1b9ab",
    "cce72e97adc2cbafade5d5770142e6f3e5a005b5",
    "6c23f9387d82ac4a06d2dfbb61626da1e2e38139",
    "eb01eb7ad69c5027408e170fc9cfd8700bf73862",
    "6096274b54f470b623bbfa1ddefb1399f9f83808",
    "966fa01c648c3fb913688ebe369f5e974e0e749f",
    "656ee86a5d221e0a912513d770dc6da60ae8e413",
    "378f5256c4c9c3da459d957ae33fb360c0ae0e4a",
    "6cf9c40e5a79e827b6205b3ae431ea9b7c27d39c",
    "987b68999af56510f068208c44bea379e9773827",
    "8805e2c876d3729ad4143a3ffe8af32bd675d6ad",
    "c14d66d4677541fca7a4e27468711d8fc7de9eed",
    "b56fc7fef64d0cf7b372de182a9a27b0cd119752",
    "281df276509dec27d1b1a77d4b73feb28ba9b2ce",
    "39b37a28714858892c80cfb921120d402abb70be",
    "4cf508ab7bbf113cbc4e2fc4b5ce88f53a078dc7",
    "abb8edd38b79b71c790a20191b858d5179f81469",
    "ac4fe331f5987c5ca986dc8a6fdd99837a1f4efa",
    "1ddb6a7814d54c11cf7963e5daffff927d4a0fab",
    "07d39bc117e83deafd54ee8b36510955eb1bcbbe",
    "ad30539bd104ffb61375f9fd60c7fc4fb5e4ea81",
    "d1df035d9f4ac5eec43eb3ff203abaf46e208af2",
    "85a26f5127684f907505348c160a774807f08c80",
    "323dbdf0b2ddab0ce991f36eab89251c5ded75f7",
    "fd62ebc635453704c2d92db0b619eb8f7e5a3aed",
    "1aa081dd13ea34e686d91bc8a9d4d015b271191c",
    "5b4f1fc21f36c010ebfaa046da0093489cd5bcf9"
};

#define TEST_NAME "test sha0"

int test_sha0()
{
    int failed = 0;
    size_t i = 0;
    unsigned char hash[20];
    char hashStr[41] = { 0 };

    char string[150];
    memset(string, 'a', 150);

    for (; i <= 150; i++) {
        CHashLib_SHA0_hash((const unsigned char*) string, i, hash);
        BufferToHex(hash, 20, hashStr, 41);
        if (strcmp(hashStr, expectedHash[i]) != 0) {
            failed++;
        }
    }

    if (failed == 0) {
        printf("%-40s " COLOR_TEXT("OK", COLOR_GREEN) "\n", TEST_NAME);
        return 0;
    }

    printf("%-36s " COLOR_TEXT("FAILED", COLOR_RED) "\n", TEST_NAME);
    return 1;
}