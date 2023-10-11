using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public float speed = 8f; // 플레이어 이동 속도
    public float moveableRange = 5.5f; // 플레이어가 움직일 수 있는 범위
    public float power = 1000f; // 포탄 발사 속도
    public GameObject cannonBall; // 포탄의 프리팹(미리 만들어진 게임 오브젝트 템플릿)
    public Transform spawnPoint; // 포탄이 생성될 위치

    // Update is called once per frame
    void Update()
    {
        // 플레이어 캐릭터의 이동을 처리하는 부분

        // 입력(Input)을 통해 플레이어 캐릭터를 좌우로 움직입니다.
        //Input.GetAxisRaw("Horizontal"): Input.GetAxisRaw 함수는 사용자 입력을 가져옵니다. "Horizontal"은 사용자가 좌우 화살표 키나 "A"와 "D" 키와 같은 좌우 이동 입력을 나타냅니다. 이 입력값은 -1.0(왼쪽), 0.0(정지), 1.0(오른쪽)과 같이 반환됩니다.
        transform.Translate(Input.GetAxisRaw("Horizontal") * speed * Time.deltaTime, 0, 0);

        // 플레이어 캐릭터의 위치를 'moveableRange' 변수로 제한하여 범위 내에서만 움직일 수 있도록 합니다.
        transform.position = new Vector2(
            //Clamp 함수는 주어진 값이 특정 범위 내에 있는지 확인하고, 범위를 벗어난 경우 해당 값을 범위 내로 조정합니다.
            Mathf.Clamp(transform.position.x, -moveableRange, moveableRange),
            transform.position.y);

        // 스페이스 바를 누르면 Shoot 메서드를 호출하여 포탄을 발사합니다.
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Shoot();
        }
    }

    void Shoot()
    {
        // 포탄을 발사하는 부분

        // 'cannonBall' 프리팹을 'spawnPoint' 위치에 생성합니다.
        GameObject newBullet = Instantiate(cannonBall, spawnPoint.position, Quaternion.identity) as GameObject;

        // 새로 생성된 포탄에 Rigidbody2D 컴포넌트를 사용하여 'power' 값으로 위로 힘을 가합니다.
        newBullet.GetComponent<Rigidbody2D>().AddForce(Vector3.up * power);
    }
}
