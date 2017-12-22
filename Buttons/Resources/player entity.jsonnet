local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    Collision: {},
    PlayerInput: {},
    PlayerJump: {},
    PlayerKeys: {},
    StaticSpriteRendering: {
      sprite: "player",
      depth: common.getDepth("player")
    },
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "player body.json"
    }
  }
}
