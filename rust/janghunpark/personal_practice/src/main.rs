use futures::executor::block_on;

// 비동기 함수
async fn sample()
{
    for _ in 0..3
    {
        println!("sample");
    }
}

fn main() {
    let future = sample();
    block_on(future);
    println!("End");
}
