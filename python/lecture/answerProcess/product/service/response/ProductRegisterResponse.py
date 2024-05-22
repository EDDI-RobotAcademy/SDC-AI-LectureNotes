from dataclasses import dataclass


@dataclass
class ProductRegisterResponse:
    __id: int
    __name: str
    __price: int
    __details: str
    __accountId: str




