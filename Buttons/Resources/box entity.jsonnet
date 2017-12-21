local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "size"]) {
    StaticSpriteRendering: {
      sprite: "box"
    },
    Transform: {},
    PhysicsBody: common.getPosSize(params) + {
      body: "box body.json"
    }
  }
}
