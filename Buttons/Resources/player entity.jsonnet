local common = import "common.jsonnet";

function(params) {
  components: {
    Collision: {},
    PlayerInput: {},
    PlayerJump: {},
    PlayerKeys: {},
    PlayerRendering: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "player body.json"
    }
  }
}
